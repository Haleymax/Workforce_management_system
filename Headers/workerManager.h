//
// Created by huang on 2024/6/6.
//


#pragma once   //防止头文件重复包含
#include "iostream"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

class WorkerManager{
public:
    //构造函数
    WorkerManager();

    //显示菜单
    void Show_Menu();

    //退出系统
    void ExitSystem();

    //添加职工
    void Add_Emp();




    ~WorkerManager();

public:
    int m_EmpNum; //职工人数

    Worker ** m_EmpArray;  //记录职工数组指针
};

WorkerManager::WorkerManager() {
    //初始化属性
    this->m_EmpNum = 0;

    //初始化数组指针
    this->m_EmpArray = NULL;
}

WorkerManager::~WorkerManager() {
    if (this->m_EmpArray != NULL)
        delete[] this->m_EmpArray;
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


//添加职工的实现
void WorkerManager::Add_Emp() {
    cout << "请输入增加的职工数量" << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0){
        //采用可变长数组的形式放入新职工，新开辟一个数组来存放替代原来的旧数组

        //计算新空间的大小
        int newSize = this->m_EmpNum + addNum;

        //开辟新空间
        Worker ** newSpace = new Worker * [newSize];

        //将原空间下内容存放到新空间下
        if (this->m_EmpNum != NULL){
            for (int i = 0; i < this->m_EmpNum; ++i) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //输入新数据
        for (int i = 0; i < addNum; ++i) {
            int id;
            string name;
            int dSelect;

            cout<< "请输入第 " << i + i << " 个新职工编号 ：" <<endl;
            cin >> id;

            cout<< "请输入第 " << i + 1 << "个新职工姓名 : " <<endl;
            cin >> name;

            cout << "请选择g该职工的岗位 : " << endl;
            cout << "1、普通职工" <<endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            //创建新职工
            Worker *worker = NULL;
            switch (dSelect) {
                case 1:   //普通职工
                    worker = new Employee(id,name,1);
                    break;
                case 2: //经理
                    worker = new Manager(id,name,2);
                    break;
                case 3: //老板
                    worker = new Boss(id,name,3);
                    break;
                default:
                    break;
            }

            newSpace[this->m_EmpNum + i] = worker;
        }
        //释放原有空间
        delete[] this->m_EmpArray;

        //管理系统的职工信息数组指向新开的数组中
        this->m_EmpArray = newSpace;

        //更新职工数量
        this->m_EmpNum = newSize;

        //提示添加成功
        cout << "成功添加" << addNum << "名新职工！" << endl;
    } else{
        cout << "输入有误" <<endl;
    }

    system("pause");
    system("cls");
}
