#ifndef CESWALL_H
#define CESWALL_H
namespace game_framework {

	class CGMap;
	class CESWall
	{
	public:
		CESWall();
		void LoadBitmap();										// �d��D��
		void Initialize();										// ��ʼ��
		void OnShow(float sx, float sy);						// ���D���N������
		void SetXY(float nx, float ny);							// �O���A�ĵ�����
		void SetIsAlive(bool alive);							// �O����ըǽ���Ƿ����
		bool GetIsAlive();										// ��ȡ��ըǽ����״̬
		float  GetX1();											// ��ȡ��ըǽ�����Ͻ� x ����
		float  GetY1();											// ��ȡ��ըǽ�����Ͻ� y ����
		float  GetX2();											// ��ȡ��ըǽ�����½� x ����
		float  GetY2();											// ��ȡ��ըǽ�����½� y ����
		void ResetAnimation();									// ���ö�������
		~CESWall();
	private:
		CAnimation eswall_live;									// ��ըǽ����ŵĄӮ�
		CAnimation eswall_dead;									// ��ըǽ�������ĄӮ�
		bool isAlive;											// �Ƿ����
		float x, y;												// ��ըǽ�������
	};
}
#endif
