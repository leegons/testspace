<?php

// auto load class
class Lgn
{
	static protected $legal_classname_pattern = '/^[a-zA-Z0-9_]{0,32}$/';
	// auto load
	static public function _j_autoload_($classname) {
		if (!preg_match(self::$legal_classname_pattern, $classname)) {
			return;
		}		
		// change Common_Db_Base to common/db/Base
		$nclassname = '';
		$e = explode('_', $classname);
		$p = array_pop($e);
		while ($p != '/') {
			$nclassname = $p . $nclassname;
			$p = strtolower(array_pop($e)) . '/';
		}
		$include_path = array('./lib/');
		foreach ($include_path as $path) {
			$filename = $path . $nclassname . '.php';
			if (file_exists($filename)) {
				require_once $filename;
				break;
			}
		}
	}
	
	// init
	static public function init() {
		spl_autoload_register(array(__CLASS__, '_j_autoload_'));
	}
}

Lgn::init();
// init log
if (defined('__MODEL_NAME__')) {
	$modelname = __MODEL_NAME__;
	Common_Log::set('normal_log', 'log/'.$modelname.'.log');
	Common_Log::set('alter_log', 'log/'.$modelname.'.log');
}
