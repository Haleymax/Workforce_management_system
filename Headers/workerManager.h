//
// Created by huang on 2024/6/6.
//


#pragma once   //防止头文件重复包含
#include "iostream"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include "fstream"
#define FILENAME "empFile.txt"

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

    //保存文件
    void save();

    //统计职工人数
    int get_EmpNum();




    ~WorkerManager();

public:
    int m_EmpNum; //职工人数

    Worker ** m_EmpArray;  //记录职工数组指针

    bool m_FileIsEmpty; //标志文件是否为空
};

WorkerManager::WorkerManager() {

    ifstream ifs;  //输出文件流
    ifs.open(FILENAME,ios::in);

    //文件不存在情况
    if (!ifs.is_open()){
        cout << "文件不存在" << endl;
        //初始化人数
        this->m_EmpNum = 0;

        //初始化数组指针
        this->m_EmpArray = NULL;

        //初始化文件为空标志
        this->m_FileIsEmpty = true;

        ifs.close();
        return;
    }

    //文件存在，且没有记录
    char ch;
    ifs >> ch;
    if (ifs.eof()){
        cout << "文件为空!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    //文件存在且有数据，获取人数
    int num = this->get_EmpNum();
    cout << "职工个数为 : " << num << endl;
    this->m_EmpNum = num; //更新职工人数


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

        //更新职工不为空的标志
        this->m_FileIsEmpty = false;

        //提示添加成功
        cout << "成功添加" << addNum << "名新职工！" << endl;

        //将数据写入文件中
        this->save();
    } else{
        cout << "输入有误" <<endl;
    }

    system("pause");
    system("cls");
}


//退出系统
void WorkerManager::ExitSystem() {
    cout << "欢迎下次使用" <<endl;
    system("pause");
    exit(0);
}

void WorkerManager::save() {
    ofstream ofs;  //输入文件流
    ofs.open(FILENAME,ios::out);

    for (int i = 0; i < this->m_EmpNum; ++i) {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}

int WorkerManager::get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId){
        //记录人数
        num++;
    }
    ifs.close();

    return num;
}