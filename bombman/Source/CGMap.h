#ifndef CGMAP_H
#define CGMAP_H
#include <map>
#include <vector>
#include "CESWall.h"
#include "CProps.h"
#include "CPlayer.h"
#include "CMonster.h"
#include <algorithm>

namespace game_framework {

	class CProps;
	class CGMap 
	{
	public:
		CGMap();
		void LoadBitmap();												// �����ͼ
		void OnShow();													// ��ʾ��ͼ
		void OnMove();													// λ���߼���Ŀǰ����Ҫʵ�֣�
		void ShowMap(int map[15][40]);									// ��ʾ��ͼ
		void ShowCutFigure();											// �й���ͼ
		void AssignMap(int map[15][40]);								// ��gamemap��ֵ
		void SwitchingMap();											// �л���ͼ
		bool HitRectangle(float tx1, float ty1, float tx2, float ty2, CPlayer *player);	//����Ƿ��������������ľ���
		bool HitRectangle(float tx1, float ty1, float tx2, float ty2);					//����Ƿ��������������ľ���
		bool HitRectangleOfMonster(float tx1, float ty1, float tx2, float ty2);			//����Ƿ��������������ľ��������������
		bool HitRectangleOfProps(CPlayer *player, CGMap *gamemap, CMonster *monster);	//����Ƿ��������������ľ��������ŵ���
		void ChangePass(CPlayer *player, CGMap *gamemap,bool x);		// �������йع���
		bool HitRectangleOfSpeed(CPlayer *player);						//����Ƿ��������������ľ������ڼ��ٵ���
		bool HitRectangleOfBombnum(CPlayer *player);					//����Ƿ��������������ľ������ڼ�ը��������
		bool HitRectangleOfBombpow(CPlayer *player);					//����Ƿ��������������ľ������ڼ�ը����������
		bool HitRectangleOfMissAll(CPlayer *player);					//����Ƿ��������������ľ��������޵е���
		bool HitRectangleOfCrossBomb(CPlayer *player);					//����Ƿ��������������ľ������ڴ�ը������
		bool HitRectangleOfControl(CPlayer *player);					//����Ƿ��������������ľ������ڿ���ը������
		bool HitRectangleOfCrossWall(CPlayer *player);					//����Ƿ��������������ľ������ڴ�ǽ����
		bool HitRectangleOfMissFire(CPlayer *player);					//����Ƿ��������������ľ����������ӻ������
		void InitializeForRestart();									// ��ʼ����ըǽ�������ؿ���Ϸ
		void SetIsAliveByXY(float x, float y, bool flag);				// ����XY������������ǽ��Ĵ��״̬
		void SetLevel(int x);											// ���ùؿ�
		int GetLevel();													// ��ȡĿǰ�ؿ���
		float GetIndexOfESWallByXY(float x, float y);					// ����XY�����ȡ��ըǽ�������
		vector<pair<float, float>> GetCoordinatesOfTheWall();			// ��ȡ��ըǽ������꣬��������Ϊmultimap��
		vector<pair<float, float>> GetCoordinatesOfTheMonster();		// ��ȡ��������꣬��������Ϊvector<pair<float, float>>��
		vector<pair<float, float>> GetCoordinatesOfAllWalls();			// ��ȡ����ǽ������꣨Ӳǽ����ǽ��
		vector<pair<float, float>> GetCoordinatesOfclearing();			// ��ȡ�յ�����
		void DeleteBrokenWallCoordinates(float x, float y);				// ����XY����ɾ����Ӧ����ǽ
		void ClearnCorrdinates();										// �������vector�ﴢ�������
		int GetMonsterNum();											// ��ȡ���������
		void SetIsCutFigure(bool cutFigure);							// �趨�й�
		bool GetIsCutFigure();											// ��ȡ�й�
		void SetStart(time_t s);										// ��ȡ���������
		void MovingScreen(CPlayer *player);								// �ƶ��Ӵ�
		void SetSX(float sx);											// ���ӫĻ�������
		float GetSX();													// ���ӫĻ�������
		float GetSY();													// ���ӫĻ�ұ�����
		~CGMap();														// ��������
	private:
		CMovingBitmap green;											// ������ɫ��ͼ
		CMovingBitmap grey;												// ������ɫ��ͼ
		CMovingBitmap wall;												// ����ǽ�ĵ�ͼ
		vector<CMovingBitmap*> cutFigure;								// ����ͼ
		bool isCutFigure;												// �жϹ���ͼ�Ƿ���ʾ
		CDoor		  door;												// ��
		CSpeed		  speed;											// ����
		CBombnum	  bombnum;											// ��ը����
		CBombpow	  bombpow;											// ������
		CMissAll	  missall;											// �޵�
		CCrossBomb	  crossbomb;										// ��ը��
		CControl	  control;											// ����ը��
		CCrossWall    crosswall;										// ��ǽ
		CMissFire     missfire;											// ���ӻ���
		CAnimation animation;											// ��ըǽ�Ķ���
		time_t start;													// ��ʼʱ��
		time_t end;														// ����ʱ��
		int gamemap[15][40];											// ����һ����ͼ�����index
		vector<pair<float, float>>eswalls;								// ��ſ�ըǽ������
		vector<pair<float, float>> monsters;							// ��Ź�������
		vector<pair<float, float>> walls;								// ���ǽ�����꣨����Ӳǽ����ǽ��
		vector<pair<float, float>> clearing;							// ��ſյ�����
		float SX = 0, SY = 0;											// (sx, sy)��ΞĻ(�����Ͻ�)�ڵ؈D�ϵ��c����
		const float MW, MH;												// ÿ��С��ͼ�ĸߡ���
		vector<CESWall*> ceswall;										// ��ſ�ըǽ��
		const int ESWALLNUM;											// ��ըǽ����������ֵ��
		const int MONSTERNUM;											// ��������������ֵ��
		int level;														// �ؿ�ֵ
		bool cycletime;													// �ж��Ƿ�ѭ��һ��
	};
}
#endif