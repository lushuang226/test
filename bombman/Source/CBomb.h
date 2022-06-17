#ifndef CBOMB_H
#define CBOMB_H
#include <ctime>
#include <vector>
#include <map>
#include <cmath>
namespace game_framework {

	class CBomb {
	public:
		CBomb();										// ��ʼ��
		void LoadBitmap();								// �d��D��
		void OnMove();									// �Ƅ�
		void OnShow(float sx, float sy);				// ���D���N��ӫĻ
		void SetXY(float x, float y);					// ����ը��XY����
		void SetSpace(bool flag);						// ����isSpace����
		float GetX();									// ��ȡx����
		float GetY();									// ��ȡy����
		bool GetIsSpace();								// ��ȡisSpace����
		bool GetIsAlive();								// ��ȡisAlive����
		void SetIsAlive(bool flag);						// ����isSpace����
		void SetIsEnd(bool flag);						// ����isEnd����
		bool GetIsEnd();								// ��ȡisEnd����
		void ResetAnimation();							// ���ö�������
		void SetIsUse(bool flag);						// ����isUse����
		bool GetIsUse();								// ��ȡisUse����
		void SetStart(int time);						// ����start����
		void SetEnd(int time);							// ����end����
		bool HitRectangleOfBomb(float tx1, float ty1, float tx2, float ty2);											// �Ƿ��������������ľ��Σ�����ը�����HitRectangle��
		bool HitRectangleOfExplosion(float tx1, float ty1, float tx2, float ty2);										// �Ƿ��������������ľ������ڻ���
		bool HitRectangleOfExplosion(float tx1, float ty1, float tx2, float ty2, vector<pair<float, float>> eswalls);	// �Ƿ��������������ľ���
		void SetFire(vector<pair<float, float>> walls);																	// ���û��泤������ը����������ǽ�����
		void SetBombLevel(int level);																					// ����ը���ȼ�
		int GetBombLevel();																								// ��ȡը���ȼ�
		~CBomb();
	private:
		float x, y;					// �D������
		CAnimation bomb;			// ը���Ķ���
		CAnimation explode;			// ��ը����
		CAnimation uptop;			// ը���϶������涯��
		CAnimation righttop;		// ը���Ҷ������涯��
		CAnimation lefttop;			// ը���󶥲����涯��
		CAnimation dowmtop;			// ը���µײ�����
		vector<CAnimation*> up;		// up��ը����
		vector<CAnimation*> down;	// down��ը����
		vector<CAnimation*> left;	// left��ը����
		vector<CAnimation*> right;	// right��ը����
		int btime;					// ը������ʱ��
		bool isSpace;				// �ж������Ƿ񰴿ո�
		bool isUse;					// �ж�ը����״̬�Ƿ�Ϊ��ʹ��״̬
		bool isAlive;				// �ж�ը���Ƿ�ը
		bool isEnd;					// �ж�ը���Ƿ���ȫ��ը
		time_t start;				// ��¼ը���ͷ�ʱ��ʱ���
		time_t end;					// ��¼ը������ʱ��ʱ���
		bool utop;					// �����ж�ը���������涯���ܷ����
		bool dtop;					// �����ж�ը���µͲ����涯���ܷ����
		bool rtop;					// �����ж�ը���Ҷ������涯���ܷ����
		bool ltop;					// �����ж�ը���󶥲����涯���ܷ����
		bool bombing;				// �����ж�ը���Ƿ�ը
		const int FIRENUM;			// ����ը������ȼ�����
		int bomb_level;				// ը���ȼ�����
		int ubomb_level;			// ը���ȼ�����
		int dbomb_level;			// ը���ȼ�����
		int lbomb_level;			// ը���ȼ�����
		int rbomb_level;			// ը���ȼ�����
	};

}
#endif

