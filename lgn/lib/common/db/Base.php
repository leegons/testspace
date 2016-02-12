<?php

/** 
 * base database manager
 * @author lijian04
 * 
 */
class Common_Db_Base {
	/* DataBase Configure */
	private static $host = 'localhost:3306';
	private static $user = 'root';
	private static $pswd = '234234';
	private static $db   = 'sqlleegons';
	
	private static $_con;
	
	/**
	 * query a sql and get result source
	 * @param string $query sql
	 * @return boolean|resource
	 */
	public static function query($query) {
		if (!self::_check_con()) {
			return false;
		}
		//var_dump($query);
		return mysql_query($query, self::$_con);
	}
	
	/**
	 * query a sql and get all data by array
	 * @param string $query sql
	 * @return boolean|multitype:array
	 */
	public static function fetch($query) {
		$res = self::query($query);
		if (!$res) {
			return false;
		}
		return mysql_fetch_array($res, MYSQL_ASSOC);
	}
	
	/**
	 * query a sql and fetch all result by array
	 * @param string $query sql
	 * @return boolean|multitype:multitype:array
	 */
	public static function fetchAll($query) {
		$res = self::query($query);
		if (!$res) {
			return false;
		}
		$result = array();
		while (false != ($row = mysql_fetch_array($res, MYSQL_ASSOC))) {
			$result[] = $row;
		}
		return $result;
	}
	
	/**
	 * get error message for nerest operat
	 * @return string
	 */
	public static function error() {
		return mysql_error(self::$_con);
	}
	
	private static function _check_con() {
		if (!self::$_con) {
			return self::_connect();
		}
		return self::$_con;
	}
	
	private static function _connect() {
		self::$_con = mysql_connect(self::$host, self::$user, self::$pswd);
		if (!self::$_con) {
			return false;
		}
		if (!mysql_query('CREATE DATABASE IF NOT EXISTS ' . self::$db, self::$_con)) {
			return false;
		}
		if (!mysql_query("set names'UTF8'")) {
			return false;
		}
		return mysql_select_db(self::$db, self::$_con);
	}
}
