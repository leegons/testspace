<?php

/**
 * passport manager. table [user, pswd, nick, register_time, islock]
 * @author lijian04
 */
class Common_Db_Passport extends Common_Db_Table {
	
	/* Configure for Database */
	protected $fields = array(
			'user' => array('type' => 'varchar', 'len' => 32, 'notnull' => true),
			'pswd' => array('type' => 'varchar', 'len' => 32, 'notnull' => true),
			'nick' => array('type' => 'varchar', 'len' => 32, 'defaul'  => ''),
			'register_time' => array ('type' => 'datetime'),
			'islock' => array('type' => 'int', 'default' => 0),
	);
	protected $indexs = array(
			'key_user' => array('user'),
	);
	
	private static $_instance = array();
	
	/**
	 * get instance, one name point to one table
	 * @param string $name
	 * @return multitype: instance
	 */
	public static function getInstance($name = 'base') {
		$tname = 'pass' . $name;
		if (!isset(self::$_instance[$tname])) {
			self::$_instance[$tname] = new self($tname);
		}
		return self::$_instance[$tname];
	}
	
	/**
	 * inserUser into databases
	 * @param array $user include ['user', 'pswd', 'nick']
	 * @return boolean is success
	 */
	public function insertUser($user) {
		if (!isset($user['user'], $user['pswd'], $user['nick'])) {
			return false;
		}
		if ($this->isUserExists($user['user'])) {
			return false;
		}
		$user['register_time'] = date('Y-m-d h:i:s');
		$this->insert($user);
	}
	
	/**
	 * delete one user by username
	 * @param string $user username
	 * @return boolean|Ambigous <boolean, resource>
	 */
	public function deleteUser($user) {
		if (!isset($user)) {
			return false;
		}
		if (!$this->isUserExists($user)) {
			return false;
		}
		return $this->delete(array('user' => $user));
	}
	
	/**
	 * check is user exists
	 * @param string $user
	 * @return boolean
	 */
	public function isUserExists($user) {
		return $this->isExists($user, 'user');
	} 
	
	/**
	 * check is user and pswd currect
	 * 
	 */
	public function checkUser($user, $pswd) {
		$rcd = $this->getOne(array('user' => $user));
		if (!$rcd || !isset($rcd['pswd'])) {
			return false;
		}
		return $pswd == $rcd['pswd'];
	}
}
