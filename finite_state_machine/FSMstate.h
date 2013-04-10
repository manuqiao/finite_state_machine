
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
	//一个构造函数，可以接受这个状态的ID和它支持的转换数目
	FSMstate (int iStateID, unsigned usTransitions);

	//析构函数，清除分配的数组
	~FSMstate ();

	//取这个状态的ID
	int GetID ()
	{
		return m_iStateID;
	}

	//向数组中增加状态转换
	void AddTransition (int iInput,int iOutputID);

	//从数组中删除一个状态转换
	void DeleteTransition (int iOutputID);

	//进行状态转换并得到输出状态
	int GetOutput (int iInput);

private:
	unsigned m_usNumberOfTransition; //状态的最大数
	int* m_piInputs; //为了转换而使用的输入数组
	int* m_piOutputState; //输出状态数组
	int m_iStateID; //这个状态的唯一标识符
};