#pragma once
class BaseMenuState
{
public : 
	virtual void ShowTitle() = 0;
	virtual void ShowBody() = 0;
	virtual int NextActionMenu() = 0;
};