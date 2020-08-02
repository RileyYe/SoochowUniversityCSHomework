#pragma once
class Activity // 任何交互（包括退出程序）都是一个活动
{
public:
	virtual void run() = 0; // 一个运行的接口， 子类实现它以完成具体交互
	virtual void show_name() const = 0; // 一个打印自己名字的接口
	virtual ~Activity() {}
};