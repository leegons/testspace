<?php

class Common_AjaxRequest
{
	// params from uri
	public $param;
	// input encode
	public $ie;
	// output encode
	public $oe;
	// result data
	protected $result;
	// inner encode
	static public $inner_encode = 'utf8';
	
	public function __construct() {
		$this->get_param();
		$this->get_sysconf();
		$this->result = array();
	}
	
	/**
	 * deal sysconf from uri
	 *   include:
	 *     ie          -- in_encode
	 *     oe          -- out_encode
	 *     cb|callback -- callback 
	 */
	protected function get_sysconf() {
		if (isset($this->param['ie'])) {
			$this->ie = strtolower($this->param['ie']);
		}
		$this->ie = $this->encoding_normalize($this->ie);
		
		if (isset($this->param['oe'])) {
			$this->oe = strtolower($this->param['oe']);
		}
		$this->oe = $this->encoding_normalize($this->oe);
		
		if ($this->ie != self::$inner_encode) {
			$this->param = self::iconv_arr($this->ie, self::inner_encode, $this->param);
		}
		
		if (isset($this->param['cb'])) {
			$this->cb = $this->param['cb'];
		} else if (isset($this->param['callback'])) {
			$this->cb = $this->param['callback'];
		} else {
			$this->cb = '';
		}
		$this->cb = htmlspecialchars($this->cb);
	}
	/**
	 * push data into result
	 * 		ALTER: value will be covered by same key if exists
	 * @param string $key
	 * @param string $value
	 */
	public function setResult($key, $value) {
		$this->result[$key] = $value;
	}
	/**
	 * get all result as json encode
	 * @return string
	 */
	public function getReturn() {
		if ($this->oe != self::$inner_encode) {
			$this->result = self::iconv_arr(self::$inner_encode, $this->oe, $this->result);
		}
		$json_result = json_encode($this->result);
		if (!empty($this->cb)) {
			$json_result = $this->cb . '(' . $json_result . ')';
		}
		return $json_result;
	}
	/**
	 * conv encode
	 * @param string $in_encode
	 * @param string $out_encode
	 * @param array $arr
	 * @return multitype:string
	 */
	static protected function iconv_arr($in_encode, $out_encode, $arr) {
		$result = array();
		foreach ($arr as $k => $v) {
			if (is_string($arr[$k])) {
				$result[$k] = iconv($in_encode, $out_encode, $arr[$k]);
			}
		}
		return $result;
	}
	
	/**
	 * change encode normalize
	 * @param string $encode
	 * @param string $default
	 * @return string
	 */
	protected function encoding_normalize($encode, $default = 'utf8') {
		$e = strtolower($encode);
		switch ($e) {
			case 'gbk':
			case 'gb2312':
			case 'gb18030':
			case 'utf8':
				break;
			case 'utf-8':
				$e = 'utf8';
				break;
			default:
				$e = $default;
				break;
		}
		return $e;
	}
	
	// get param from uri
	protected function get_param() {
		foreach ($_GET as $k=>$v) {
			$this->param[$k] = $v;
		}
		foreach ($_POST as $k=>$v) {
			$this->param[$k] = $v;
		}
	} 
}