#include "Common.h"


char* SERVERIP = (char*)"127.0.0.1";
#define SERVERPORT 9000
#define BUFSIZE 1024
#define WM_LBUTTONDOWN 0x0201  // ���� �䱸 �޽��� ID ��
#define MAX_CLIENT_COUNT 3 // 3�� �÷��� ����


fd_set read_fds;  // �б� ������ ������ üũ�� ���� ��ũ���� ����
fd_set write_fds; // ���� ������ ������ üũ�� ���� ��ũ���� ����

//���μ��� ������ �̰����� ���� ó������ ������
//ƽ�� ��Ŷ �ְ� ���������� �������ʿ����� ī�޶����Ŵ� �ʿ���µ� �ִϸ��̼� �����̰ų� �׷��Ŵ� ƽ�������ϸ� �ʴ� 60��������
//�̺κ� ������ �ʿ����� HP�� ī�޶�� �̺�Ʈ�ø� ������ �����ϴ°ɷ�?


//���Ϳ� �浹ó���Ǹ� �� ������ó���ؼ� ������ ������ ���� ������
//������ ������ ������ �ڵ尡�ְ� �ű� �ִ� hp �� �����ͼ� ������ ������ hp ���� - �ϴ°ɷ�?
DWORD WINAPI Game_Damage_Info_Thread(LPVOID param) {


    return 1;
}

//������ �ٰ��� �ؾ��ϴ°� ó���� ������
//�Ұ� üũ�ؼ� �������� �������� �Ƚ������� üũ
//���� �巡�׵� ���� �� �޾ƿ�
//���� ���� ĳ���͸� ���� �ʿ� ������?
//ĳ���Ͱ� �������� ���������ٸ� ���ó���ϰ� �����ʿ� �̵�
//�̰� ����Ű���
DWORD WINAPI Tino_ability_info_Thread(LPVOID param) {
    

    return 1;
}

//ĳ���͵��� ������
// �̰� ���� �ؾ�����? �ִϸ��̼���? ������ ĳ���� �����ϱ� � �ִϸ��̼��� �۵��ǰ� �ִ��� ������ �����ٸ� �ٸ� Ŭ������ ������ �ϳ�?
//�̺κ� ã���ʿ� ���� �𸮾󼭹��� ÷�̶�
//�Ǵ°Ű����ѵ� ���� �����ʿ�

DWORD WINAPI Move_info_Thread(LPVOID param) {
    SOCKET* client_sockets = (SOCKET*)param;  // Ŭ���̾�Ʈ ���� �迭�� �Ű������� ����
    int client_count = MAX_CLIENT_COUNT;

    // select() ����
    while (1) {
        FD_ZERO(&read_fds);  // �б� ���� �ʱ�ȭ
        FD_ZERO(&write_fds); // ���� ���� �ʱ�ȭ

        // Ŭ���̾�Ʈ ������ �б� ���տ� �߰�
        for (int i = 0; i < client_count; ++i) {
            if (client_sockets[i] != INVALID_SOCKET) {
                FD_SET(client_sockets[i], &read_fds);
            }
        }

        // select() ȣ�� (Ÿ�Ӿƿ��� NULL�� �����Ͽ� ���ŷ ���� ���)
        int result = select(0, &read_fds, NULL, NULL, NULL);
        if (result == SOCKET_ERROR) {
            printf("select() ����: %d\n", WSAGetLastError());
            break;
        }

        // �� Ŭ���̾�Ʈ���� ������ �ޱ�
        for (int i = 0; i < client_count; ++i) {
            if (FD_ISSET(client_sockets[i], &read_fds)) {
                // Ŭ���̾�Ʈ�κ��� ���� ������ ó��
                char buffer[BUFSIZE];
                int bytes_received = recv(client_sockets[i], buffer, sizeof(buffer), 0);

                if (bytes_received > 0) {
                    // �����Ͱ� ���������� ���ŵǾ����� �ٸ� Ŭ���̾�Ʈ���� ����
                    printf("Ŭ���̾�Ʈ %d�� ������: %s\n", i + 1, buffer);

                    // �ٸ� Ŭ���̾�Ʈ���� ������ ����
                    for (int j = 0; j < client_count; ++j) {
                        if (i != j && client_sockets[j] != INVALID_SOCKET) {
                            // �ٸ� Ŭ���̾�Ʈ���� ������ ����
                            send(client_sockets[j], buffer, bytes_received, 0);
                        }
                    }
                }
                else if (bytes_received == 0) {
                    // Ŭ���̾�Ʈ ���� ����
                    printf("Ŭ���̾�Ʈ %d�� ������ �����߽��ϴ�.\n", i + 1);
                    closesocket(client_sockets[i]);
                    client_sockets[i] = INVALID_SOCKET;
                }
                else {
                    // ���� �߻�
                    printf("recv() ����: %d\n", WSAGetLastError());
                }
            }
        }
    }

    return 0;
}

//�̺κ� �����κ� ī�޶����� ������ ���ڸ� �޾Ƽ� �ϴ°� �ɰŰ��⵵ �ϰ� �̸��κ����γ�����ǳ�?
//ī�޶� �ϴ¹� ã���ؼ� �̰� �𸮾� �ʿ� �����Ű�� ���� �ٲٴ°ɷ� �ϸ�ɰŰ��� �������
//���� ���常 �Ѿ�� ������ġ�� ���� ���Ѿ��ϳ�??
//����������� �� �Ѿ�� �ű⿡ �´� ī�޶�� ���� ������Ű�� �������� �����
//��������
DWORD WINAPI View_info_Thread(LPVOID param) {

    return 1;

}

int main(int argc, char* argv[]) {
    
    int retval;

    // ���� �ʱ�ȭ
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        return 1;

    // ���� ����
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

    // ������ ��ſ� ����� ����
    SOCKET client_sock;
    struct sockaddr_in clientaddr;
    int addrlen;
    char buf[BUFSIZE + 1];


    // Ŭ���̾�Ʈ ���� �迭
    SOCKET client_sockets[MAX_CLIENT_COUNT] = { 0 };
    int client_count = 0;
    
    


    while (client_count < MAX_CLIENT_COUNT) {
        addrlen = sizeof(clientaddr);
        SOCKET client_socket = accept(listen_sock, (struct sockaddr*)&clientaddr, &addrlen);
        if (client_socket == INVALID_SOCKET) {
            printf("accept() ����: %d\n", WSAGetLastError());
            continue;
        }

        client_sockets[client_count] = client_socket;
        send(client_socket, (char*)&client_count, sizeof(client_count), 0);
        printf("Ŭ���̾�Ʈ %d ����\n", client_count);
        client_count++;
    }

    
    printf("��� Ŭ���̾�Ʈ ���� �Ϸ�!\n");
    float x, y, z, a, b, c;
    fd_set read_fds;
    struct timeval timeout;
    timeout.tv_sec = 0.1;  // 1�� Ÿ�Ӿƿ�
    timeout.tv_usec = 0;

    while (1) {
        FD_ZERO(&read_fds);

        // ���� ���ϰ� Ŭ���̾�Ʈ ������ ���
        for (int i = 0; i < client_count; i++) {
            FD_SET(client_sockets[i], &read_fds);
        }

        // `select()` ����: Ŭ���̾�Ʈ ���� �߿��� �����Ͱ� ������ ���� �ִ��� Ȯ��
        int ready = select(0, &read_fds, NULL, NULL, &timeout);

        if (ready == SOCKET_ERROR) {
            printf("select() ����: %d\n", WSAGetLastError());
            break;
        }

        // �����Ͱ� �ִ� Ŭ���̾�Ʈ ���ϸ� ó��
        for (int i = 0; i < client_count; i++) {
            if (FD_ISSET(client_sockets[i], &read_fds)) {
                char buf[48];  // 6���� float �� (�� 4����Ʈ)
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
                   

                    // �ٸ� Ŭ���̾�Ʈ�鿡�� ������ ����
                    for (int j = 0; j < client_count; j++) {
                        if (j != i) {
                            send(client_sockets[j], (char*)&i, sizeof(i), 0);  // ���� ID ����
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
                    printf("Ŭ���̾�Ʈ %d ���� ����\n", i);
                    closesocket(client_sockets[i]);

                    // �迭���� �ش� Ŭ���̾�Ʈ�� ���� (���� ����)
                    for (int k = i; k < client_count - 1; k++) {
                        client_sockets[k] = client_sockets[k + 1];
                    }
                    
                }
                else {
                    printf("recv() ����: %d\n", WSAGetLastError());
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






    printf("��� �÷��̾� ���� �Ϸ�\n");
    //���⿡�� �� ���� ������ �κ�� ���� ����ǰ�? ����ٸ� �Ƹ� Ŭ�󿡼� ����� �������� �װ� Ȯ�ΰ� ������ �������� ����Ű��� ���¼������ ������Ǵϱ�
    // �Ѵٸ� ���� �ؿ� ��������

    //������ ���� �κ� ����ؿ� ��������
    //CreateThread(NULL, 0, Move_info_Thread, (LPVOID)client_sockets, 0, NULL);


    //���� �ݱ�
    for (int i = 0; i < client_count; i++) {
        shutdown(client_sockets[i], SD_BOTH);
        closesocket(client_sockets[i]);
    }
    closesocket(listen_sock);

    // ���� ����
    WSACleanup();
    return 0;

}