#ifndef CPROPS_H
#define CPROPS_H
#include "CPlayer.h"
#include "CMonster.h"
#include <algorithm>
namespace game_framework {

	class CGMap;
	class CProps
	{
	public:
		CProps();
		bool IsAlive();															// �Ƿ����
		void SetXY(float nx, float ny);											// �O������
		void SetIsAlive(bool alive);											// �O���Ƿ����
		bool HitRectangle(CPlayer *player, vector<pair<float, float>> eswalls);	// �Ƿ��������������ľ���
		bool HitRectangles(float tx1, float ty1, float tx2, float ty2);			// �Ƿ��������������ľ���
		float  GetX1();															// ��ȡ���Ͻ� x ����
		float  GetY1();															// ��ȡ���Ͻ� y ����
		float  GetX2();															// �������½� x ����
		float  GetY2();															// �������½� y ����
	protected:
		float x, y;																// ����
		bool is_alive;															// �Ƿ����		
	};
	// ======================================��================================================
	class CDoor :public CProps 
	{
	public:
		bool HitRectangleFromDoor(CPlayer *player, CGMap *gamemap, vector<pair<float, float>> eswalls, CMonster *monster);		// ����������һ��ǰ�������й�ɱ��
		void LoadBitmap();																										// �d��ͼ��	
		void OnShow(float sx, float sy);																						// �N������
		void ChangePass(CPlayer *player, CGMap *gamemap, bool flag);															// �йع���
	protected:
		CMovingBitmap door;				
	};
	// ======================================����================================================
	class CSpeed :public CProps
	{
	public:
		bool HitRectangleFromSpeed(CPlayer *player, vector<pair<float, float>> eswalls);										// �������ٵ��߻�ʹ�����ٶ�����50%
		void LoadBitmap();
		void OnShow(float sx, float sy);
	protected:
		CMovingBitmap speed;					
	};
	// ======================================��ը����================================================
	class CBombnum :public CProps																								
	{
	public:
		bool HitRectangleFromBombNum(CPlayer *player, vector<pair<float, float>> eswalls);										// ������ը�����߻�ʹ����Я��ը����+1
		void LoadBitmap();
		void OnShow(float sx, float sy);
	protected:
		CMovingBitmap bombnum;				
	};
	// ======================================������================================================
	class CBombpow :public CProps
	{
	public:
		bool HitRectangleFromBombPow(CPlayer *player, vector<pair<float, float>> eswalls);										// �������������߻�ʹ����ը������+1
		void LoadBitmap();
		void OnShow(float sx, float sy);
	protected:
		CMovingBitmap bombpow;			
	};
	// ======================================��ǽ================================================
	class CCrossWall :public CProps
	{
	public:
		bool HitRectangleFromCrossWalls(CPlayer *player, vector<pair<float, float>> eswalls);									// ������ǽ���߻�ʹ������봩ǽ״̬
		void LoadBitmap();
		void OnShow(float sx, float sy);
	protected:
		CMovingBitmap crosswall;
	};
	// ======================================��ը��================================================
	class CCrossBomb :public CProps
	{
	public:
		bool HitRectangleFromCrossBomb(CPlayer *player, vector<pair<float, float>> eswalls);									// ������ը�����߻�ʹ������봩ը��״̬
		void LoadBitmap();
		void OnShow(float sx, float sy);
	protected:
		CMovingBitmap crossbomb;
	};
	// ======================================����ը��================================================
	class CControl :public CProps
	{
	public:
		bool HitRectangleFromBombControl(CPlayer *player, vector<pair<float, float>> eswalls);									// ��������ը�����߻�ʹ������������ը��״̬
		void LoadBitmap();
		void OnShow(float sx, float sy);
	protected:
		CMovingBitmap control;
	};
	// ======================================�޵�================================================
	class CMissAll :public CProps
	{
	public:
		bool HitRectangleFromMissAll(CPlayer *player, vector<pair<float, float>> eswalls);										// �����޵е��߻�ʹ��������޵�״̬
		void LoadBitmap();
		void OnShow(float sx, float sy);
	protected:
		CMovingBitmap missall;
	};
	// ======================================���ӻ���================================================
	class CMissFire :public CProps
	{
	public:
		bool HitRectangleFromMissFire(CPlayer *player, vector<pair<float, float>> eswalls);										// �������ӻ�����߻�ʹ����������ӻ���״̬
		void LoadBitmap();
		void OnShow(float sx, float sy);
	protected:
		CMovingBitmap missfire;
	};
}
#endif