#include "Common.h"


enum PacketType {
    GET_PLAYER_PACKET,
    Move_CONTROL_PACKET,
    Damage_PACKET,
    TINO_ABILITY_PACKET,
    CAMERA_VIEW_PACKET
};
//�̺κ��� ĳ������ hp�κ��� UI�� ���̰� �ϴ� �κ�
//ĳ������ hp�� ���� �ĺ���ȣ�� ���� UI�� ���̰� �ϸ� �ɰŰ���
struct get_player{
    PacketType packetType = GET_PLAYER_PACKET;
    int hp;
    int character_code;
};
//�Ƹ� �̰����� ĳ������ �������� ����ϴ� ����
//�ʿ��ϴٸ� �� �߰��ϸ鼭 �Ұ�
//���� �𸮾��� �ڵ尡 ���� �Ǵ��� �ָ��ؼ� �׺κ� ���� ����鼭 �ؾ��ҵ�
struct key_control {
    PacketType packetType = Move_CONTROL_PACKET;
    float x;
    float y;
    float z;
    uint32_t nMessageID;
};
//�� �κ��� �������� ����ϴ� �κ�
//�Ұ����� �������� �������� ������ �ް� �巡�׵� ��ġ�� ������ ���� ���� ��ġ�� �̵� �� �巡�׵� ���� ������ x y��ǥ�� ����� ��� ó���Ұ�
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
//�̺κ��� �浹üũ�ؼ� ���� ���� hp�� ��� �׷� �ڵ��� ���� �ɵ� �浹üũ�� Ŭ�󿡼� �浹ó���� �̺�Ʈ�� ������ �Ұ� �����°ɷ��ұ�? �ƴϸ� ��������?
//���� ���� �ִ� ü�� �������� �� �ִ� ü�¿��� ������ ������ ������?�̷��� ����ȭ�Ǹ鼭 �ɰŰ�����
struct damage_control {
    PacketType packetType = Damage_PACKET;
    int enemy_hp;
    int enemy_code;
    int damage;
};
//���ӿ��� �װ�Ƽ�� �������� �� �� �����κ� �Ѿ������ ī�޶� �ٲ� �� ī�޶� ���� ���� ������ ���� Ÿ�� ����X
struct View_control {
    PacketType packetType =  CAMERA_VIEW_PACKET;
};