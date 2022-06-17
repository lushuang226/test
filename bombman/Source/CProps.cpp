#pragma once
#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CProps.h"
#include "CGMap.h"

namespace game_framework {

	CProps::CProps()
	{
		is_alive = true;
		x = y = 0.0;
	}

	float CProps::GetX1()
	{
		return x;
	}

	float CProps::GetY1()
	{
		return y;
	}

	float CProps::GetX2()
	{
		return x + 32.0;
	}

	float CProps::GetY2()
	{
		return y + 32.0;
	}

	bool CProps::IsAlive()
	{
		return is_alive;
	}

	void CProps::SetIsAlive(bool alive)
	{
		is_alive = alive;
	}

	bool CProps::HitRectangle(CPlayer * player, vector<pair<float, float>> eswalls)
	{
		if (HitRectangles(player->GetX1() + 3, player->GetY1() + 3, player->GetX2() - 3, player->GetY2() - 3) && is_alive == true) {
			vector<pair<float, float>>::iterator it;
			it = find(eswalls.begin(), eswalls.end(), make_pair(x, y));
			if (it == eswalls.end()) {
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}

	bool CProps::HitRectangles(float tx1, float ty1, float tx2, float ty2)
	{
		float x1 = x + 3.0;					// ���Ͻ�x����
		float y1 = y + 3.0;					// ���Ͻ�y����
		float x2 = x1 + 32.0 - 3.0;			// ���½�x����
		float y2 = y1 + 32.0 - 3.0;			// ���½�y����
		return (tx2 >= x1 && tx1 <= x2 && ty2 >= y1 && ty1 <= y2);
	}

	void CProps::SetXY(float nx, float ny)
	{
		x = nx; y = ny;
	}

	// ======================================��================================================
	bool CDoor::HitRectangleFromDoor(CPlayer *player, CGMap *gamemap, vector<pair<float, float>> eswalls, CMonster *monster)//��������Ǽ����û���������ߣ������ͼ�����õ��߹ؿ���
	{
		int flag = 0;
		for (int i = 0; i < gamemap->GetMonsterNum(); i++)
		{
			if (monster[i].IsAlive())
				flag++;
		}
		// �z�y�Ƿ�����
		if (HitRectangle(player, eswalls) && flag == 0) {
			ChangePass(player, gamemap, true);
			return true;
		}
		flag = 0;
		return false;
	}

	void CDoor::LoadBitmap()
	{
		door.LoadBitmap(IDB_DOOR);										// �d��D��
	}

	void CDoor::OnShow(float sx, float sy)
	{
		if (is_alive) {
			door.SetTopLeft(x - sx, y - sy);
			door.ShowBitmap();
		}
	}

	void CDoor::ChangePass(CPlayer *player, CGMap *gamemap, bool flag)	// �������йع���
	{
		if (flag == true) {
			float speed = player->GetSpeed();			
			int bombnum = player->GetBombNum();			
			player->Initialize();						
			player->InitializeBomb();					
			player->SetSpeed(speed);					
			player->SetBombNum(bombnum);				
			gamemap->ClearnCorrdinates();				
			gamemap->InitializeForRestart();
			gamemap->SetLevel(gamemap->GetLevel() + 1);	
			gamemap->SwitchingMap();					
			gamemap->SetIsCutFigure(true);				
			gamemap->SetStart(time(NULL));	
			gamemap->SetSX(0.0);
		}
	}

	// ======================================����================================================
	bool CSpeed::HitRectangleFromSpeed(CPlayer * player, vector<pair<float, float>> eswalls)
	{
		if (HitRectangle(player, eswalls)) {
			player->AddSpeed(0.5);														// ����
			is_alive = false;
			return true;
		}
		return false;
	}

	void CSpeed::LoadBitmap()
	{
		speed.LoadBitmap(IDB_SPEED);
	}

	void CSpeed::OnShow(float sx, float sy)
	{
		if (is_alive) {
			speed.SetTopLeft(x - sx, y - sy);
			speed.ShowBitmap();
		}
	}

	// ======================================��ը����================================================
	bool CBombnum::HitRectangleFromBombNum(CPlayer * player, vector<pair<float, float>> eswalls)
	{
		if (HitRectangle(player, eswalls)) {
			player->SetBombNum(player->GetBombNum() + 1);								// ��ը����
			is_alive = false;
			return true;
		}
		return false;
	}

	void CBombnum::LoadBitmap()
	{
		bombnum.LoadBitmap(IDB_BOMBNUM);
	}
	
	void CBombnum::OnShow(float sx, float sy)
	{
		if (is_alive) {
			bombnum.SetTopLeft(x - sx, y - sy);
			bombnum.ShowBitmap();
		}
	}

	// ======================================������================================================
	bool CBombpow::HitRectangleFromBombPow(CPlayer * player, vector<pair<float, float>> eswalls)
	{
		if (HitRectangle(player, eswalls)) {
			player->SetBombPow();														//������
			is_alive = false;
			return true;
		}
		return false;
	}
	
	void CBombpow::LoadBitmap()
	{
		bombpow.LoadBitmap(IDB_BOMBPOW);
	}

	void CBombpow::OnShow(float sx, float sy)
	{
		if (is_alive) {
			bombpow.SetTopLeft(x - sx, y - sy);
			bombpow.ShowBitmap();
		}
	}

	// ======================================�޵�================================================
	bool CMissAll::HitRectangleFromMissAll(CPlayer * player, vector<pair<float, float>> eswalls)
	{
		if (HitRectangle(player, eswalls)) {
			player->SetMissAll(true);													//�޵�
			is_alive = false;
			return true;
		}
		return false;
	}
	
	void CMissAll::LoadBitmap()
	{
		missall.LoadBitmap(IDB_MISSALL);
	}
	
	void CMissAll::OnShow(float sx, float sy)
	{
		if (is_alive) {
			missall.SetTopLeft(x - sx, y -sy);
			missall.ShowBitmap();
		}
	}

	// ======================================��ը��================================================
	bool CCrossBomb::HitRectangleFromCrossBomb(CPlayer * player, vector<pair<float, float>> eswalls)
	{

		if (HitRectangle(player, eswalls)) {
			player->SetCrossBomb(true);													//��ը��
			is_alive = false;
			return true;
		}
		return false;
	}
	
	void CCrossBomb::LoadBitmap()
	{
		crossbomb.LoadBitmap(IDB_CROSSBOMB);
	}
	
	void CCrossBomb::OnShow(float sx, float sy)
	{
		if (is_alive) {
			crossbomb.SetTopLeft(x - sx, y - sy);
			crossbomb.ShowBitmap();
		}
	}

	// ======================================����ը��================================================
	bool CControl::HitRectangleFromBombControl(CPlayer * player, vector<pair<float, float>> eswalls)
	{
		if (HitRectangle(player, eswalls)) {
			player->SetBombControl(true);												//����
			is_alive = false;
			return true;
		}
		return false;
	}
	
	void CControl::LoadBitmap()
	{
		control.LoadBitmap(IDB_CONTROL);
	}
	
	void CControl::OnShow(float sx, float sy)
	{
		if (is_alive) {
			control.SetTopLeft(x -sx, y - sy);
			control.ShowBitmap();
		}
	}

	bool CCrossWall::HitRectangleFromCrossWalls(CPlayer * player, vector<pair<float, float>> eswalls)
	{
		if (HitRectangle(player, eswalls)) {
			player->SetCrossWalls(true);												//��ǽ
			is_alive = false;	
			return true;
		}
		return false;
	}
	
	void CCrossWall::LoadBitmap()
	{
		crosswall.LoadBitmap(IDB_CROSSWALL);
	}
	void CCrossWall::OnShow(float sx, float sy)
	{
		if (is_alive) {
			crosswall.SetTopLeft(x - sx, y - sy);
			crosswall.ShowBitmap();
		}
	}

	bool CMissFire::HitRectangleFromMissFire(CPlayer * player, vector<pair<float, float>> eswalls)
	{
		if (HitRectangle(player, eswalls)) {
			player->SetMissFire(true);													//���ӻ���
			is_alive = false;
			return true;
		}
		return false;
	}

	void CMissFire::LoadBitmap()
	{
		missfire.LoadBitmap(IDB_MISSFIRE);
	}

	void CMissFire::OnShow(float sx, float sy)
	{
		if (is_alive) {
			missfire.SetTopLeft(x - sx, y - sy);
			missfire.ShowBitmap();
		}
	}
}
