#include "Common.h"


char* SERVERIP = (char*)"127.0.0.1";
#define SERVERPORT 9000
#define BUFSIZE 1024
#define WM_LBUTTONDOWN 0x0201  // 서버 요구 메시지 ID 값
#define MAX_CLIENT_COUNT 3 // 3인 플레이 게임


fd_set read_fds;  // 읽기 가능한 소켓을 체크할 파일 디스크립터 집합
fd_set write_fds; // 쓰기 가능한 소켓을 체크할 파일 디스크립터 집합

//메인서버 나눌지 이곳에서 전부 처리할지 생각중
//틱당 패킷 주고 받을건지도 생각할필요있음 카메라같은거는 필요없는데 애니메이션 움직이거나 그런거는 틱당으로하면 초당 60번정도라
//이부분 생각할 필요있음 HP나 카메라는 이벤트시만 보내서 갱신하는걸로?


//몬스터와 충돌처리되면 그 데미지처리해서 서버로 보내는 역할 쓰레드
//몬스터의 각각의 고유한 코드가있고 거기 최대 hp 를 가져와서 데미지 들어오면 hp 에서 - 하는걸로?
DWORD WINAPI Game_Damage_Info_Thread(LPVOID param) {


    return 1;
}

//차원술 다같이 해야하는거 처리용 쓰레드
//불값 체크해서 차원술이 써졌는지 안써졌는지 체크
//그후 드래그된 영역 값 받아옴
//그후 각각 캐릭터를 방장 쪽에 던지기?
//캐릭터가 영역밖을 빠져나간다면 즉사처리하고 방장쪽에 이동
//이건 쉬울거같음
DWORD WINAPI Tino_ability_info_Thread(LPVOID param) {
    

    return 1;
}

//캐릭터들의 움직임
// 이걸 어케 해야하지? 애니메이션을? 어차피 캐릭터 있으니까 어떤 애니메이션이 작동되고 있는지 서버로 보낸다면 다른 클라한테 보내야 하나?
//이부분 찾을필요 있음 언리얼서버는 첨이라
//되는거같긴한데 폴더 참조필요

DWORD WINAPI Move_info_Thread(LPVOID param) {
    SOCKET* client_sockets = (SOCKET*)param;  // 클라이언트 소켓 배열을 매개변수로 받음
    int client_count = MAX_CLIENT_COUNT;

    // select() 루프
    while (1) {
        FD_ZERO(&read_fds);  // 읽기 집합 초기화
        FD_ZERO(&write_fds); // 쓰기 집합 초기화

        // 클라이언트 소켓을 읽기 집합에 추가
        for (int i = 0; i < client_count; ++i) {
            if (client_sockets[i] != INVALID_SOCKET) {
                FD_SET(client_sockets[i], &read_fds);
            }
        }

        // select() 호출 (타임아웃은 NULL로 설정하여 블로킹 모드로 대기)
        int result = select(0, &read_fds, NULL, NULL, NULL);
        if (result == SOCKET_ERROR) {
            printf("select() 오류: %d\n", WSAGetLastError());
            break;
        }

        // 각 클라이언트에서 데이터 받기
        for (int i = 0; i < client_count; ++i) {
            if (FD_ISSET(client_sockets[i], &read_fds)) {
                // 클라이언트로부터 받은 데이터 처리
                char buffer[BUFSIZE];
                int bytes_received = recv(client_sockets[i], buffer, sizeof(buffer), 0);

                if (bytes_received > 0) {
                    // 데이터가 정상적으로 수신되었으면 다른 클라이언트에게 전송
                    printf("클라이언트 %d의 데이터: %s\n", i + 1, buffer);

                    // 다른 클라이언트에게 데이터 전송
                    for (int j = 0; j < client_count; ++j) {
                        if (i != j && client_sockets[j] != INVALID_SOCKET) {
                            // 다른 클라이언트에게 데이터 전송
                            send(client_sockets[j], buffer, bytes_received, 0);
                        }
                    }
                }
                else if (bytes_received == 0) {
                    // 클라이언트 연결 종료
                    printf("클라이언트 %d가 연결을 종료했습니다.\n", i + 1);
                    closesocket(client_sockets[i]);
                    client_sockets[i] = INVALID_SOCKET;
                }
                else {
                    // 오류 발생
                    printf("recv() 오류: %d\n", WSAGetLastError());
                }
            }
        }
    }

    return 0;
}

//이부분 시점부분 카메라한테 고유한 숫자를 달아서 하는게 될거같기도 하고 이름부분으로넣으면되나?
//카메라 하는법 찾긴해서 이거 언리얼 맵에 적용시키고 시점 바꾸는걸로 하면될거같음 방장기준
//만약 방장만 넘어가면 방장위치로 텔포 시켜야하나??
//방장기준으로 방 넘어가면 거기에 맞는 카메라로 전부 고정시키는 형식으로 만들듯
//폴더참조
DWORD WINAPI View_info_Thread(LPVOID param) {

    return 1;

}

int main(int argc, char* argv[]) {
    
    int retval;

    // 윈속 초기화
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        return 1;

    // 소켓 생성
    SOCKET listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == INVALID_SOCKET) err_quit("socket()");

    // bind()
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(SERVERPORT);
    retval = bind(listen_sock, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    if (retval == SOCKET_ERROR) err_quit("bind()");

    // listen()
    retval = listen(listen_sock, SOMAXCONN);
    if (retval == SOCKET_ERROR) err_quit("listen()");

    // 데이터 통신에 사용할 변수
    SOCKET client_sock;
    struct sockaddr_in clientaddr;
    int addrlen;
    char buf[BUFSIZE + 1];


    // 클라이언트 소켓 배열
    SOCKET client_sockets[MAX_CLIENT_COUNT] = { 0 };
    int client_count = 0;
    
    


    while (client_count < MAX_CLIENT_COUNT) {
        addrlen = sizeof(clientaddr);
        SOCKET client_socket = accept(listen_sock, (struct sockaddr*)&clientaddr, &addrlen);
        if (client_socket == INVALID_SOCKET) {
            printf("accept() 실패: %d\n", WSAGetLastError());
            continue;
        }

        client_sockets[client_count] = client_socket;
        send(client_socket, (char*)&client_count, sizeof(client_count), 0);
        printf("클라이언트 %d 접속\n", client_count);
        client_count++;
    }

    
    printf("모든 클라이언트 접속 완료!\n");
    float x, y, z, a, b, c;
    fd_set read_fds;
    struct timeval timeout;
    timeout.tv_sec = 0.1;  // 1초 타임아웃
    timeout.tv_usec = 0;

    while (1) {
        FD_ZERO(&read_fds);

        // 서버 소켓과 클라이언트 소켓을 등록
        for (int i = 0; i < client_count; i++) {
            FD_SET(client_sockets[i], &read_fds);
        }

        // `select()` 실행: 클라이언트 소켓 중에서 데이터가 도착한 것이 있는지 확인
        int ready = select(0, &read_fds, NULL, NULL, &timeout);

        if (ready == SOCKET_ERROR) {
            printf("select() 실패: %d\n", WSAGetLastError());
            break;
        }

        // 데이터가 있는 클라이언트 소켓만 처리
        for (int i = 0; i < client_count; i++) {
            if (FD_ISSET(client_sockets[i], &read_fds)) {
                char buf[48];  // 6개의 float 값 (각 4바이트)
                int retval = recv(client_sockets[i], buf, sizeof(buf), 0);

                if (retval > 0) {
                    float x, y, z, a, b, c,GTspeed,GTjump,ETspeed,ETjump,MTspeed,MTjump;
                    
                    memcpy(&x, buf, sizeof(float));
                    memcpy(&y, buf + 4, sizeof(float));
                    memcpy(&z, buf + 8, sizeof(float));
                    memcpy(&a, buf + 12, sizeof(float));
                    memcpy(&b, buf + 16, sizeof(float));
                    memcpy(&c, buf + 20, sizeof(float));
                    memcpy(&GTspeed, buf + 24, sizeof(float));
                    memcpy(&GTjump, buf + 28, sizeof(float));
                    memcpy(&ETspeed, buf + 32, sizeof(float));
                    memcpy(&ETjump, buf + 36, sizeof(float));
                    memcpy(&MTspeed, buf + 40, sizeof(float));
                    memcpy(&MTjump, buf + 44, sizeof(float));
                   

                    // 다른 클라이언트들에게 데이터 전송
                    for (int j = 0; j < client_count; j++) {
                        if (j != i) {
                            send(client_sockets[j], (char*)&i, sizeof(i), 0);  // 고유 ID 전송
                            send(client_sockets[j], (char*)&x, sizeof(x), 0);
                            send(client_sockets[j], (char*)&y, sizeof(y), 0);
                            send(client_sockets[j], (char*)&z, sizeof(z), 0);
                            send(client_sockets[j], (char*)&c, sizeof(c), 0);
                            send(client_sockets[j], (char*)&GTspeed, sizeof(GTspeed), 0);
                            send(client_sockets[j], (char*)&GTjump, sizeof(GTjump), 0);
                            send(client_sockets[j], (char*)&ETspeed, sizeof(ETspeed), 0);
                            send(client_sockets[j], (char*)&ETjump, sizeof(ETjump), 0);
                            send(client_sockets[j], (char*)&MTspeed, sizeof(MTspeed), 0);
                            send(client_sockets[j], (char*)&MTjump, sizeof(MTjump), 0);
                            //send(client_sockets[j], (char*)&speed, sizeof(speed), 0);
                        }
                    }
                }
                else if (retval == 0) {
                    printf("클라이언트 %d 연결 종료\n", i);
                    closesocket(client_sockets[i]);

                    // 배열에서 해당 클라이언트를 제거 (순서 유지)
                    for (int k = i; k < client_count - 1; k++) {
                        client_sockets[k] = client_sockets[k + 1];
                    }
                    
                }
                else {
                    printf("recv() 오류: %d\n", WSAGetLastError());
                }
            }
        }
    }


    for (int i = 0; i < client_count; i++) {
        shutdown(client_sockets[i], SD_BOTH);
        closesocket(client_sockets[i]);
    }
    closesocket(listen_sock);
    WSACleanup();
    return 0;






    printf("모든 플레이어 접속 완료\n");
    //여기에서 다 접속 했으면 로비로 들어가게 만들건가? 만든다면 아마 클라에서 만들고 서버에서 그거 확인값 보내는 느낌으로 만들거같음 들어온순서대로 넣으면되니까
    // 한다면 여기 밑에 넣을거임

    //쓰레드 실행 부분 여기밑에 넣을거임
    //CreateThread(NULL, 0, Move_info_Thread, (LPVOID)client_sockets, 0, NULL);


    //소켓 닫기
    for (int i = 0; i < client_count; i++) {
        shutdown(client_sockets[i], SD_BOTH);
        closesocket(client_sockets[i]);
    }
    closesocket(listen_sock);

    // 윈속 종료
    WSACleanup();
    return 0;

}