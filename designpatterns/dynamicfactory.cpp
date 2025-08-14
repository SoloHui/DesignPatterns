/***************************************************************************
  dynamicfactory.cpp - %{Cpp:License:ClassName}

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

#include "dynamicobject.h"

using namespace std;

class Api {
 public:
  virtual void test(string s) = 0;

 protected:
  Api() {}
};

class ImpleOne : public Api {
 public:
  void test(string s) { cout << "现在是One在执行" << s; }
};

class ImpleTwo : public Api {
 public:
  void test(string s) { cout << "现在是Two在执行" << s; }
};

REG_CLASS(ImpleOne)
REG_CLASS(ImpleTwo)

// int main(void) {
//   ImpleTwo* pTwo =
//       static_cast<ImpleTwo*>(CObjectFactory::createObject("ImpleTwo"));
//   pTwo->test("RegClass");
//   system("pause");
//   return 0;
// }

class AutoFactory {
 public:
  static Api* createApi() {
    Api* pApi = nullptr;
    // 指针向上转换
    pApi = static_cast<Api*>(CObjectFactory::createObject("ImpleTwo"));
    return pApi;
  }
};

int main() {
  Api* pApi = AutoFactory::createApi();
  pApi->test("哈哈完全不知道，里面的东西了");
  system("pause");
  return 0;
}
