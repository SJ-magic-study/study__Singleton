/************************************************************
URL
	https://ja.wikipedia.org/wiki/Singleton_%E3%83%91%E3%82%BF%E3%83%BC%E3%83%B3
************************************************************/
#include <stdio.h>

/************************************************************
************************************************************/

/**************************************************
**************************************************/
class SINGLETON{
private:
	SINGLETON()
	{
		printf("CONSTRUCTOR\tSINGLETON\n");
	}
	
	~SINGLETON()
	{
		printf("DESTRUCTOR\tSINGLETON\n");
	}
	
	SINGLETON(const SINGLETON&);				// Copy constructor. no define. 
	SINGLETON& operator=(const SINGLETON&);		// コピー代入演算子. no define.
	
public:
	static SINGLETON& getInstance(){
		static SINGLETON inst;
		return inst;
	}
	
	void func()
	{
		printf("singleton:func\n");
	}
};

/**************************************************
**************************************************/
class USER{
private:
	SINGLETON& Singleton;
	
public:
	USER()
	: Singleton(SINGLETON::getInstance())
	{
		printf("CONSTRUCTOR\tUSER\n");
	}
	
	~USER()
	{
		printf("DESTRUCTOR\tUSER\n");
	}
	
	void func(){
		Singleton.func();
	}
};

/**************************************************
**************************************************/
class USER_2{
private:
	SINGLETON& Singleton;
	
public:
	USER_2()
	: Singleton(SINGLETON::getInstance())
	{
		printf("CONSTRUCTOR\tUSER_2\n");
	}
	
	~USER_2()
	{
		printf("DESTRUCTOR\tUSER_2\n");
	}
	
	void func(){
		Singleton.func();
	}
};


/************************************************************
result:
	<Start>
	CONSTRUCTOR	SINGLETON
	CONSTRUCTOR	USER
	CONSTRUCTOR	USER_2
	singleton:func
	singleton:func
	<Finish>
	DESTRUCTOR	USER_2
	DESTRUCTOR	USER
	DESTRUCTOR	SINGLETON
************************************************************/
int main()
{
	printf("<Start>\n");
	
	USER user;
	USER_2 user_2;
	user.func();
	user_2.func();
	
	printf("<Finish>\n");
	
	return 0;
}
