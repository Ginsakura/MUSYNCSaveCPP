#include "stdafx.h"
#include "SQL.h"
#include "Functions.h"

SQLOperat::SQLOperat() {
	// ��������
	DB = QSqlDatabase::addDatabase("QSQLITE");
	// �������ݿ�
	DB.setDatabaseName("HitDelayHistory_v2.db");
	// �������ݿ�����
	if (DB.open()) {
		// �����α겢���ӵ����ݿ�
		cursor = QSqlQuery(DB);
		bool create = false, tableNotExists = true;
		// ��ѯ��ṹ
		while (Select("sqlite_master", "name", "type='table'").next()) {
			QString tab = tempCur.value(0).toString();
			if (tab == "HitDelayHistory") tableNotExists = false;
		}
		// ������ʱ������
		if (tableNotExists) {
			cursor.prepare("CREATE TABLE if not exists \"HitDelayHistory\" ("
				"\"SongMapName\" text NOT NULL,"
				"\"RecordTime\" TEXT,"
				"\"AvgDelay\" float,"
				"\"AllKeys\" int,"
				"\"AvgAcc\" float,"
				"\"HitMap\" text,"
				"PRIMARY KEY(\"SongMapName\", \"RecordTime\")"
				");");
			create = cursor.exec();
			if (create) {
				qout << QFgColor(0, 0xff, 0) << QString::fromLocal8Bit("HitDelayHistory�����ɹ����Ѵ���") << QResetColor();
			}
			else {
				qout << QFgColor(0xff, 0, 0) << QString::fromLocal8Bit("HitDelayHistory����ʧ��: ") << QResetColor() << cursor.lastError();
			}
		}
	}
	qout << QFgColor(0xff, 0, 0) << QString::fromLocal8Bit("��ʧ��") << QResetColor();
}

//==================================================================
//�� �� ����SelectAll
//�����������������,��ѯ����`ȫ����`��`ȫ���ֶ�`
//          select * from 'table';
//���������QString table
//�� �� ֵ��QSqlQuery || nullptr
//==================================================================
QSqlQuery SQLOperat::SelectAll(const QString table) {
	QSqlQuery cur = QSqlQuery(DB);
	cur.prepare(QString("SELECT * from %0").arg(table));
	bool state = cur.exec();
	if (state) {
		return cur;
	}
	else {
		qout << QFgColor(0xff, 0, 0) << "select error: " << QResetColor() << cur.lastError();
	}
}

//==================================================================
//�� �� ����Select
//����������ͨ����������������ֶκ�����,��ѯ`ָ����`��`ָ���ֶ�`
//          select 'getter' from 'table' where 'condition';
//���������QString table, QString getter, QString condition
//�� �� ֵ��QSqlQuery || nullptr
//==================================================================
QSqlQuery SQLOperat::Select(const QString table, const QString getter, const QString condition) {
	QSqlQuery cur = QSqlQuery(DB);
	cur.prepare(QString("select %0 from %1 where %2").arg(getter).arg(table).arg(condition));
	bool state = cur.exec();
	if (state) {
		return cur;
	}
	else {
		qout << QFgColor(0xff, 0, 0) << "select error: " << QResetColor() << cur.lastError();
	}
}

//==================================================================
//�� �� ����Select
//����������ͨ����������������ֶ�,��ѯ`ȫ����`��`ָ���ֶ�`
//          select 'getter' from 'table';
//���������QString table, QString getter = "*"
//�� �� ֵ��QSqlQuery || nullptr
//==================================================================
QSqlQuery SQLOperat::Select(const QString table, const QString getter = "*") {
	QSqlQuery cur = QSqlQuery(DB);
	cursor.prepare(QString("select %0 from %1").arg(getter).arg(table));
	bool state = cursor.exec();
	if (state) {
		return cur;
	}
	else {
		qout << QFgColor(0xff, 0, 0) << "select error: " << QResetColor() << cur.lastError();
	}
}

//==================================================================
//�� �� ����Insert
//��������������������ֶ�����ֵ,����ڲ���ָ���ֶε�����
//          Insert into 'table'('keys') values ('value');
//���������QString table, QString keys, QString value
//�� �� ֵ��bool,�Ƿ�ɹ�ִ��
//==================================================================
bool SQLOperat::Insert(const QString table, const QString keys, const QString value) {
	cursor.prepare(QString("Insert into %0(%1) values (%2);").arg(table).arg(keys).arg(value));
	bool state = cursor.exec();
	if (!state) {
		qout << QFgColor(0xff, 0, 0) << "Insert to " << table << " error: " << QResetColor() << cursor.lastError();
	}
	return state;
}

//==================================================================
//�� �� ����Insert
//�������������������ֵ,����ڲ���һ��������
//          Insert into 'table' values ('value');
//���������QString table, QString value
//�� �� ֵ��bool,�Ƿ�ɹ�ִ��
//==================================================================
bool SQLOperat::Insert(const QString table, const QString value) {
	cursor.prepare(QString("Insert into %0 values (%1)").arg(table).arg(value));
	bool state = cursor.exec();
	if (!state) {
		qout << QFgColor(0xff, 0, 0) << "Insert to" << table << " error: " << QResetColor() << cursor.lastError();
	}
	return state;
}

//==================================================================
//�� �� ����Update
//����������ͨ������������ֶΡ�ֵ������,����һ���ֶε�ֵ
//          Update 'table' set 'keys'='value' where 'condition';
//���������QString table, QString keys, QString value, QString condition
//�� �� ֵ��bool,�Ƿ�ɹ�ִ��
//==================================================================
bool SQLOperat::Update(const QString table, const QString keys, const QString value, const QString condition) {
	//qout << QString("Update %1 set '%2'='%3' where %4").arg(table).arg(keys).arg(value).arg(condition);
	cursor.prepare(QString("Update %0 set '%1'='%2' where %3").arg(table).arg(keys).arg(value).arg(condition));
	bool state = cursor.exec();
	if (!state) {
		qout << QFgColor(0xff, 0, 0) << "Update to " << table << " error: " << QResetColor() << cursor.lastError();
	}
	return state;
}

//==================================================================
//�� �� ����Delete
//����������ͨ���������������,��ɾ��ָ����������
//          delete from 'table' where 'condition';
//���������QString table, QString condition
//�� �� ֵ��bool,�Ƿ�ɹ�ִ��
//==================================================================
bool SQLOperat::Delete(QString table, QString condition) {
	cursor.prepare(QString("delete from %0 where %1").arg(table).arg(condition));
	bool state = cursor.exec();
	if (!state) {
		qout << QFgColor(0xff, 0, 0) << "Update to " << table << " error: " << QResetColor() << cursor.lastError();
	}
	return state;
}

//==================================================================
//�� �� ����Close
//�����������ر����ݿ�����,�����Query
//���������
//�� �� ֵ��
//==================================================================
void SQLOperat::Close() {
	cursor.clear();
	DB.close();
}

SQLOperat::~SQLOperat() {
	cursor.clear();
}

//==================================================================
//�� �� ����HitDelayHistory
//�����������޲ι��캯��,����һ���յ�HitDelayHistoryORM����
//���������QSqlQuery cur
//�� �� ֵ��
//==================================================================
HitDelayHistory::HitDelayHistory() {}

//==================================================================
//�� �� ����HitDelayHistory
//�����������вι��캯��,ͨ������Query��������ʼ��HitDelayHistoryORM�����ֵ
//���������QSqlQuery cur
//�� �� ֵ��
//==================================================================
HitDelayHistory::HitDelayHistory(QSqlQuery cur) {
	this->SongMapName = cur.value(0).toString();
	this->RecordTime = cur.value(1).toString();
	this->AvgDelay = cur.value(2).toDouble();
	this->AllKeys = cur.value(3).toInt();
	this->AvgAcc = cur.value(4).toDouble();
	this->HitMap = cur.value(5).toString();
	isInsert = false;
}

//==================================================================
//�� �� ����HitDelayHistory
//����������ͨ������ÿһ��������ֵ,���HitDelayHistoryORM�����ʼ��
//���������QString songMapName, QString recordTime, double avgDelay, int allKeys, double avgAcc, QString hitMap
//�� �� ֵ��
//==================================================================
HitDelayHistory::HitDelayHistory(QString songMapName, QString recordTime,
	double avgDelay, int allKeys, double avgAcc, QString hitMap) {
	this->SongMapName = songMapName;
	this->RecordTime = recordTime;
	this->AvgDelay = avgDelay;
	this->AllKeys = allKeys;
	this->AvgAcc = avgAcc;
	this->HitMap = hitMap;
}

//==================================================================
//�� �� ����save
//����������ͨ������˽�г�Ա����isInsert�ж�ִ��Insert����Update
//���������
//�� �� ֵ��bool,�Ƿ�ɹ�ִ��
//==================================================================
bool HitDelayHistory::save() {
	if (this->RecordTime == "") {
		qout << QFgColor(0xff, 0, 0) << "Record is Null." << QResetColor();
		return false;
	}
	if (isInsert) {
		sqlo = QString("\"%0\",\"%1\",%2,%3,%4,\"%5\"")
			.arg(this->SongMapName).arg(this->RecordTime).arg(this->AvgDelay)
			.arg(this->AllKeys).arg(this->AvgAcc).arg(this->HitMap);
		sql.Insert("HitDelayHistory", sqlo);
		return true;
	}
	else {
		sqlo = QString("RecordTime=\"%1\"").arg(this->RecordTime);
		sql.Update("HitDelayHistory", "SongMapName", this->SongMapName, sqlo);
		return true;
	}
}

//==================================================================
//�� �� ����change
//�����������л���ORM����Ĳ���/���¹���
//���������
//�� �� ֵ��
//==================================================================
void HitDelayHistory::change() {
	this->isInsert = !this->isInsert;
}

HitDelayHistory::~HitDelayHistory() {}