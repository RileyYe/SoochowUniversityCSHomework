支持的功能有:
输出通讯录
修改通讯录
查询条目 ( 有二级菜单 )
添加条目
保存条目
备份通讯录
安全退出

备份的通讯录在Backup目录下， 保存修改是会自动备份一份当前通讯录， 安全退出前会自动备份当前通讯录并保存条目。

理论上，telephone_directory.cpp中的每一个类都在Activity/SourceFiles/...有独立实现，而 Modify 和 Container合并在 Manage.cpp中。 
所有类继承自 Activity，Activity的声明在Activity/Headers/...中。


Modify(修改)功能是命令式，支持的命令如下：
1.  name [ a ] to [ b ] ，表示将名字为 a 的人的名字修改成 b。底层实现是 std::find_if()，因此只找一个。
2. name [ a ] del ，表示删除名字为 a 的条目。
3. phone [ a ] to [ b ]， 表示将电话号码为 a 的人的电话修改成 b。底层实现是 std::find_if()，因此只找一个。
4. phone [ a ] del， 表示删除电话号码为 a 的条目。

如果未找到或命令不存在，会分别输出 Not Found 和 Invalid Input。

选择功能时，万不可输入英文。 否则死循环。
