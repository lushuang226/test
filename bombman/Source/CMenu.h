namespace game_framework {

	class CMenu
	{
	public:
		void Initialize();						// �趨�˵���ʼֵ
		void Initialize(int num);				// �趨�˵���ʼֵ
		void LoadBitmap();						// ����ͼƬ
		void OnShow();							// ��ʾͼƬ
		void setNumber(int number);
		void setIsShow(bool flag);
		void setMovingUp(bool flag);
		void setMovingDown(bool flag);
		void setIsLeft(bool flag);
		void setIsSpace(bool flag);
		void OnMove();
		int getStatusNum();
		void setFlag(bool Flag);
		int getWay();							//��ȡ��һ���ڶ���˵��ı��룬1Ϊ��һ�㣬2λ�ڶ���
	protected:
		CMovingBitmap starts;					// �˵�ѡ��1��ͼƬ
		CMovingBitmap help;						// �˵�ѡ��2��ͼƬ
		CMovingBitmap about;					// �˵�ѡ��3��ͼƬ
		CMovingBitmap mouse;					// ���
		CMovingBitmap about_background;			// ���ڵ�ͼƬ
		CMovingBitmap player_background;		 
		bool isMovingUp;						// �Ƿ����ϼ�
		bool isMovingDown;						// �Ƿ����¼�
		bool isShow;							// ��ʾ
		bool isLeft;							// ��������˳��ڶ���˵�
		bool isSpace;							// ���¿ո����ڶ���˵�
		bool flag;								   
		int x, y;								// ��һ��˵���Сը���˵�����
		int way;								// ��ȡ�˵����� ��1Ϊ��һ�㣬2Ϊ�ڶ���
	private:
		int number;
	};
}