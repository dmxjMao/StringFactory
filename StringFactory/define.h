#pragma once

//工具条个数
enum TB_ENUM {
	TB_INT,
	//TB_FLOAT,
	TB_NUM
};

//const int TB_BUTTON_NUM = 0;//工具条按钮个数是可扩展的
const int TB_MENU_NUM = 10; //工具条按钮下拉菜单个数

//输出状态
enum OUTPUT_STATUS {
	OUTPUT_OK,//已生成
	OUTPUT_NOTYET,//未生成
	OUTPUT_STATUS_BUF
};