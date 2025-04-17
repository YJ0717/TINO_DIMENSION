#include "Common.h"


enum PacketType {
    GET_PLAYER_PACKET,
    Move_CONTROL_PACKET,
    Damage_PACKET,
    TINO_ABILITY_PACKET,
    CAMERA_VIEW_PACKET
};
//이부분은 캐릭터의 hp부분이 UI에 보이게 하는 부분
//캐릭터의 hp와 고유 식별번호를 통해 UI에 보이게 하면 될거같음
struct get_player{
    PacketType packetType = GET_PLAYER_PACKET;
    int hp;
    int character_code;
};
//아마 이곳에서 캐릭터의 움직임을 담당하는 정보
//필요하다면 더 추가하면서 할것
//현재 언리얼의 코드가 어케 되는지 애매해서 그부분 같이 만들면서 해야할듯
struct key_control {
    PacketType packetType = Move_CONTROL_PACKET;
    float x;
    float y;
    float z;
    uint32_t nMessageID;
};
//이 부분은 차원술을 담당하는 부분
//불값으로 차원술이 써졌는지 정보값 받고 드래그된 위치값 받을거 그후 방장 위치로 이동 및 드래그된 영역 밖으로 x y좌표가 벗어나면 즉사 처리할거
struct tino_ability {
    PacketType packetType = TINO_ABILITY_PACKET;
    bool Ability_check;
    float drag_x;
    float drag_y;
    float chr_x;
    float chr_y;
    float chr_z;
    int character_code;
};
//이부분은 충돌체크해서 내가 적의 hp를 깎는 그런 코드라고 보면 될듯 충돌체크는 클라에서 충돌처리시 이벤트로 서버에 불값 보내는걸로할까? 아니면 데미지만?
//방의 몬스터 최대 체력 가져오고 그 최대 체력에서 데미지 뺀값을 보낼까?이러면 동기화되면서 될거같은데
struct damage_control {
    PacketType packetType = Damage_PACKET;
    int enemy_hp;
    int enemy_code;
    int damage;
};
//게임에서 겜공티노 기준으로 맵 이 일정부분 넘어갈때마다 카메라가 바뀜 그 카메라에 대한 정보 변수는 아직 타입 생각X
struct View_control {
    PacketType packetType =  CAMERA_VIEW_PACKET;
};