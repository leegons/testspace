<?php

/** 
 * @author lijian04
 * 
 */
abstract class Common_Db_Table {

	protected $tablename;
	
	protected function init_db_conf() {
	}
	
	/* User Configure, Modify if you extends me */
	protected $fields = array(
			'user' => array(
					'type' => 'varchar',
					'len'  => 20,
					'notnull' => true,
					'default' => 'this',
			),
	);
	protected $indexs = array(
			'key_user' => array('user'),
	);
	
	// common prefix for database table
	protected $prefix = 'lgn_';
	
	public function __construct($name = null) {
		// table name 
		if ($name == null) {
			$name = 'test';
		}
		$this->tablename = $this->prefix . $name;
		// init by sub class
		$this->init_db_conf();
		// init by base class
		if (!$this->_init_db()) {
			throw new Exception('Init db failed:' . $this->error());
		}
	}
	/**
	 * check if record is exists
	 * @param string $value the value of filed 
	 * @param string $field field name
	 * @return boolean
	 */
	public function isExists($value, $field = 'id') {
		if ($field != 'id' && !isset($this->fields[$field])) {
			var_dump("not exists field[$field] = $value");
			return false;
		}
		$res = $this->getCount(array($field => $value));
		return intval($res) > 0;
	}
	/**
	 * delete records which match condition
	 * @param array $select the record's condition
	 * @return boolean|Ambigous <boolean, resource>
	 */
	public function delete($select) {
		if (!$select || count($select) <= 0) {
			return false;
		}
		$sql = 'DELETE from ' . $this->tablename . ' WHERE ' . Common_Db_Util::splice('AND', $select);
		return Common_Db_Base::query($sql);
	}
	/**
	 * insert a record
	 * @param array $data
	 * @return boolean|Ambigous <boolean, resource>
	 */
	public function insert($data) {
		if (!$data || count($data) <= 0) {
			return false;
		}
		$sql = 'INSERT INTO ' . $this->tablename . ' SET ' . Common_Db_Util::splice(',', $data);
		return Common_Db_Base::query($sql);
	}
	/**
	 * modify a record which match select condition 
	 * @param array $set new values
	 * @param array $select record condition for modify 
	 * @return boolean|Ambigous <boolean, resource>
	 */
	public function modify($set, $select) {
		if (!$set || !$select) {
			return false;
		}
		$sql = 'UPDATE ' . $this->tablename 
				. ' SET ' . Common_Db_Util::splice(',', $set) 
				. ' WHERE ' . Common_Db_Util::splice('AND', $select)
				. ' LIMIT 1';
		return Common_Db_Base::query($sql);
	}
	/**
	 * modify records which matched select condition
	 * @param array $set new value
	 * @param array $select record contidtion for modify
	 * @return boolean|Ambigous <boolean, resource>
	 */
	public function multimodify($set, $select) {
		if (!$set || !$select) {
			return false;
		}
		$sql = 'UPDATE ' . $this->tablename
				. ' SET ' . Common_Db_Util::splice(',', $set)
				. ' WHERE ' . Common_Db_Util::splice('AND', $select);
		return Common_Db_Base::query($sql);
	}
	/**
	 * get count of records which matched select condition
	 * @param array $select
	 * @return boolean|number
	 */
	public function getCount($select) {
		if (!$select || count($select) <= 0) {
			return false;
		}
		$sql = 'SELECT count(0) as res FROM ' . $this->tablename . ' WHERE ' . Common_Db_Util::splice('AND', $select);
		$res = Common_Db_Base::fetch($sql);
		if (!$res || !isset($res['res'])) {
			return false;
		}
		return intval($res['res']);
	}
	
	/**
	 * get one result by select contidion
	 * @param array $select sql condition
	 * @return boolean|Ambigous <boolean, multitype:array, multitype:>
	 */
	public function getOne($select) {
		if (!$select || count($select) <= 0) {
			return false;
		}
		$sql = 'SELECT * FROM ' . $this->tablename . ' WHERE ' . Common_Db_Util::splice('AND', $select) . 'LIMIT 1';
		return Common_Db_Base::fetch($sql);
	}
	
	/**
	 * get all result in one turn
	 * @param array $select sql condition
	 * @return boolean|Ambigous <boolean, multitype:multitype:array, multitype:multitype: >
	 */
	public function getAll($select) {
		if (!$select || count($select) <= 0) {
			return false;
		}
		$sql = 'SELECT * FROM ' . $this->tablename . ' WHERE ' . Common_Db_Util::splice('AND', $select);
		return Common_Db_Base::fetchAll($sql);
	}
	
	/**
	 * get result in paging
	 * @param array $select sql condition
	 * @param number $resultnum result num in need
	 * @param number $pagenum start number
	 * @return boolean|Ambigous <boolean, multitype:multitype:array, multitype:multitype: >
	 */
	public function getPaging($select, $resultnum, $pagenum = 0) {
		if (!$select || count($select) <= 0) {
			return false;
		}
		$sql = 'SELECT * FROM ' . $this->tablename . ' WHERE ' . Common_Db_Util::splice('AND', $select)
			. ' LIMIT ' . intval($pagenum) . ',' . intval($resultnum);
		return Common_Db_Base::fetchAll($sql);
	}
	
	/**
	 * TODO in feature
	 * @param array $data
	 */
	public function insertMulti($data) {
		//TODO
	}
	
	/**
	 * get nerest error massage
	 * @return string
	 */
	public function error() {
		return Common_Db_Base::error();
	}
	
	private function _init_db() {
		$sql = 'CREATE TABLE IF NOT EXISTS ' . $this->tablename . ' ( ';
		$sql .= '`id` bigint(20) NOT NULL AUTO_INCREMENT';
		foreach ($this->fields as $name => $v) {
			if (!isset($v['type'])) { //neccessary
				continue;
			}
			$fieldstr = ', ';
			$fieldstr .= sprintf("`%s` %s", $name, $v['type']);
			if (isset($v['len'])) {
				$fieldstr .= sprintf("(%d)", intval($v['len']));
			}
			if (isset($v['notnull']) && $v['notnull'] === true) {
				$fieldstr .= ' NOT NULL ';
			}
			if (isset($v['default'])) {
				if (is_numeric($v['default'])) {
					$fieldstr .= sprintf(' DEFAULT %d ', $v['default']);
				} else {
					$fieldstr .= sprintf(" DEFAULT '%s' ", $v['default']);
				}
			}
			$sql .= $fieldstr;
		}

		$sql .= ', PRIMARY KEY (`id`)';
		foreach ($this->indexs as $name => $v) {
			if (count($v) <= 0) { //neccessary
				continue;
			}
			$indexstr = sprintf(', KEY `%s` (', $name);
			foreach ($v as $field) {
				$indexstr .= sprintf(' `%s`,', $field);
			}
			$indexstr = substr($indexstr, 0, -1); //sub last ','
			$indexstr .= ')';
			$sql .= $indexstr;
		}
		$sql .= ') ENGINE=InnoDB DEFAULT CHARSET=utf8 ';
		return Common_Db_Base::query($sql);
	}
}
