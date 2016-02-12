<?php

class Common_Ajax extends Common_AjaxRequest
{
	static private $_con;
	static private $_finish;
	
	static public function getInstance() {
		if (!self::$_con) {
			self::$_con = new self();
			self::$_finish = false;
			ob_start();
		}
		return self::$_con;
	}
	
	public function pushResult() {
		if (self::$_finish) {
			return ;
		}
		self::$_finish = true;
		
		ob_end_clean();
		echo $this->getReturn();
	}
	
	public function __destruct() {
		$this->pushResult();
	}
}