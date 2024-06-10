//
// Created by huang on 2024/6/6.
//

#include "Headers/workerManager.h"
#include "Headers/worker.h"
#include "Headers/employee.h"
#include "Headers/manager.h"
#include "Headers/boss.h"



int main(){

    //测试案例
    //test();

    //实例化管理者对象
    WorkerManager w;
    w.init_Emp();

    int choice = 0;  //用于存储用户的选项

    while (true){
        w.Show_Menu();
        cout << "请输入您的选择 :" <<endl;
        cin >> choice;  //接受用户的选项


        switch (choice) {
            case 0:     //退出系统
                w.ExitSystem();
                break;
            case 1:     //增加员工
                w.Add_Emp();
                break;
            case 2:     //显示职工
                w.show_Emp();
                break;
            case 3:     //删除职工
                w.Del_Emp();
                break;
            case 4:     //修改职工
                w.Mod_Emp();
                break;
            case 5:     //查找职工
                w.Find_Emp();
                break;
            case 6:     //排序职工
                w.Sort_Emp();
                break;
            case 7:     //清空文档
                break;
            default:
                system("cls");
                break;
        }
    }



}