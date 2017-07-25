//消息处理的前置条件（LED灯亮、Message显示、Warning显示）
enum Precondition
{
	can,
	cl15,
	always
};

//Led灯优先级
enum Led_Priority
{
	Priority1,
	Priority2
};

//Message优先级
enum Message_Priority
{
    Message_Priority1,
    Message_Priority2
};

//Warning优先级
enum Warning_Priority
{
    Warning_Priority1,
    Warning_Priority2
};

//Led灯信号种类
enum Led_Action_Type
{
	type1,
	type2
};

//Warning灯信号种类
enum Warning_Action_Type
{
	warning_type1,
	warning_type2
};

//Message灯信号种类
enum Message_Action_Type
{
	message_type1,
	message_type2
};

//告警取消方式
enum Cancel_Type
{
	general
};