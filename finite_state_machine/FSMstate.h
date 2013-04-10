
enum {
	STATE_ID_UNCARING = 1,
	STATE_ID_MAD = 2,
	STATE_ID_RAGE = 3,
	STATE_ID_BERSERK = 4,
	STATE_ID_ANNOYED = 5
};

enum {
	INPUT_ID_PLAYER_SEEN =1,
	INPUT_ID_PLAYER_ATTACK = 2,
	INPUT_ID_PLAYER_GONE = 3,
	INPUT_ID_MONSTER_HURT = 4,
	INPUT_ID_MONSTER_HEALED = 5
};

class FSMstate
{
public:
	//һ�����캯�������Խ������״̬��ID����֧�ֵ�ת����Ŀ
	FSMstate (int iStateID, unsigned usTransitions);

	//����������������������
	~FSMstate ();

	//ȡ���״̬��ID
	int GetID ()
	{
		return m_iStateID;
	}

	//������������״̬ת��
	void AddTransition (int iInput,int iOutputID);

	//��������ɾ��һ��״̬ת��
	void DeleteTransition (int iOutputID);

	//����״̬ת�����õ����״̬
	int GetOutput (int iInput);

private:
	unsigned m_usNumberOfTransition; //״̬�������
	int* m_piInputs; //Ϊ��ת����ʹ�õ���������
	int* m_piOutputState; //���״̬����
	int m_iStateID; //���״̬��Ψһ��ʶ��
};