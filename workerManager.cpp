//
// Created by huang on 2024/6/6.
//

#include "Headers/workerManager.h"
#include "Headers/worker.h"
#include "Headers/employee.h"
#include "Headers/manager.h"
#include "Headers/boss.h"



int main(){

    //���԰���
    //test();

    //ʵ���������߶���
    WorkerManager w;
    w.init_Emp();

    int choice = 0;  //���ڴ洢�û���ѡ��

    while (true){
        w.Show_Menu();
        cout << "����������ѡ�� :" <<endl;
        cin >> choice;  //�����û���ѡ��


        switch (choice) {
            case 0:     //�˳�ϵͳ
                w.ExitSystem();
                break;
            case 1:     //����Ա��
                w.Add_Emp();
                break;
            case 2:     //��ʾְ��
                w.show_Emp();
                break;
            case 3:     //ɾ��ְ��
                w.Del_Emp();
                break;
            case 4:     //�޸�ְ��
                w.Mod_Emp();
                break;
            case 5:     //����ְ��
                w.Find_Emp();
                break;
            case 6:     //����ְ��
                w.Sort_Emp();
                break;
            case 7:     //����ĵ�
                break;
            default:
                system("cls");
                break;
        }
    }



}