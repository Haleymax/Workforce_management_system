//
// Created by huang on 2024/6/6.
//


#pragma once   //防止头文件重复包含
#include "iostream"
#include "Headers/worker.h"

using namespace std;

class WorkerManager{
public:
    //构造函数
    WorkerManager();

    //显示菜单
    void Show_Menu();

    //退出系统
    void ExitSystem();




    ~WorkerManager();

public:
    int m_EmpNum; //职工人数

    Worker ** m_EmpArray;  //记录职工数组指针
};

WorkerManager::WorkerManager() {

}

WorkerManager::~WorkerManager() {

}
void WorkerManager::Show_Menu()
{
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

WorkerManager::WorkerManager() {
    //初始化属性
    this->m_EmpNum = 0;

    this->m_EmpArray = NULL;
}