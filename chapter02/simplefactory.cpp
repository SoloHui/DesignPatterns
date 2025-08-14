/***************************************************************************
  simplefactory.cpp - SimpleFactory

 ---------------------
 begin                : 13.8.2025
 copyright            : (C) 2025 by Jinghui Liang
 email                : 3414467112@qq.com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Api {
 public:
  virtual void test(string s) = 0;

 protected:
  Api() {}  // 屏蔽构造函数,体现接口
};

class ImpleOne : public Api {
 public:
  void test(string s) { cout << "现在是One在执行" << s; }
};

class ImpleTwo : public Api {
 public:
  void test(string s) { cout << "现在是Two在执行" << s; }
};

class Factory {
 public:
  static Api* createApi(int type) {
    Api* pApi = nullptr;
    if (type == 1) {
      pApi = new ImpleOne();
    }
    if (type == 2) {
      pApi = new ImpleTwo();
    }
    return pApi;
  }

  static Api* createApi() { return new ImpleOne(); }
};

// 传入参数1，可以实现从数据库读入的功能
// 传入参数2，可以实现从文本文件读入的功能

int main(int argc, char const* argv[]) {
  Api* pApi = Factory::createApi(2);  //客户端，还是知道工厂的细节

  pApi->test("现在是使用简单工厂方法");
  Api* pApiEx = Factory::createApi();
  system("pause");
  return 0;
}

// 实现了客户端调用和implOne，implTwo的解耦合
// factory类实现了变化隔离
