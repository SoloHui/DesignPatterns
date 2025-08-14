/***************************************************************************
  dynamicobject.h - %{Cpp:License:ClassName}

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
#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H
#include <map>
#include <string>
/**
 * @brief typedef 关键字
 *
 * 用于定义一个函数指针类型:
 *  - `typedef` - 创建类型别名的关键字
 *  - `void*` - 函数的返回类型（返回void指针）
 *  - `(*Constructor)` - 函数指针的名称，括号表明这是指针
 *  - `()` - 函数的参数列表（空参数，不接受任何参数）
 *
 * > 即: Constructor 表示的类型为 void* xxx()
 */
typedef void* (*Constructor)();

class CObjectFactory {
 public:
  static void registerClass(std::string className, Constructor constructor) {
    constructors()[className] = constructor;
  }

  static void* createObject(const std::string& className) {
    Constructor constructor = NULL;
    if (constructors().find(className) != constructors().end())
      constructor = constructors().find(className)->second;

    if (constructor == NULL) return NULL;
    return (*constructor)();
  }

 private:
  // string->key:动态创建的类的类名，value是构建
  inline static std::map<std::string, Constructor>& constructors() {
    static std::map<std::string, Constructor> instance;
    return instance;
  }
};

#define REG_CLASS(class_name)                                           \
  class class_name##Helper {                                            \
   public:                                                              \
    class_name##Helper() {                                              \
      CObjectFactory::registerClass(#class_name,                        \
                                    class_name##Helper::createObjFunc); \
    }                                                                   \
    static void* createObjFunc() { return new class_name; }             \
  };                                                                    \
  class_name##Helper class_name##helper;
#endif  // DYNAMICOBJECT_H
