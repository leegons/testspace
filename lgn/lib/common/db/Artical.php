<?php

/**
 *
 * @author lijian04
 *        
 */
class Common_Db_Artical extends Common_Db_Table {
	private static $_atc_instance = array(); 
	
	protected $fields = array(
			'title'   => array('type'=>'varchar', 'len'=>256, 'default'=>'UNDEFINE'),
			'content' => array('type'=>'text'),
			'ftime'   => array('type'=>'datetime'),
			'father'  => array('type'=>'bigint', 'default'=>0),
	);
	protected $indexs = array(
			'key_title' => array('title'),
	);
	/**
	 * get a instance
	 * @param string $name dbname
	 * @return multitype:Common_Db_Artical
	 */
	public static function getInstance($name) {
		$tname = 'atc_' . $name;
		if (!isset(self::$_atc_instance[$tname])) {
			self::$_atc_instance[$tname] = new self($tname);
		}
		return self::$_atc_instance[$tname];
	}
	/**
	 * insert a articl 
	 * @param array $atc include[title, content, father, ftime]
	 * @return boolean|Ambigous <boolean, resource>
	 */
	public function insertAtc($atc) {
		if (!isset($atc['title'], $atc['content'])) {
			return false;
		}
		$insert = array(
				'title'   => $atc['title'],
				'content' => $atc['content'],
				'father'  => isset($atc['father']) ? intval($atc['father']) : 0,
				'ftime'   => date('Y-m-d h:i:s'),
		);
		return $this->insert($insert);
	}
	/**
	 * get a artical by ID
	 * @param number $id
	 * @return Ambigous <boolean, Ambigous, multitype:array, multitype:>
	 */
	public function getAtcById($id) {
		return $this->getOne(array('id' => $id));
	}
	/**
	 * get some artical by paging
	 * @param number $resultnum
	 * @param number $pagenum
	 * @return Ambigous <boolean, Ambigous, multitype:multitype:array, multitype:multitype: >
	 */
	public function getAtcPaging($resultnum, $pagenum = 0) {
		return $this->getPaging(array('id'=>array('t'=>'>','v'=>1)), $resultnum, $pagenum);
	}
}
