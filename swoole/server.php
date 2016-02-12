<?php

$serv = new swoole_http_server("127.0.0.1", 9502);

$serv->on('Request', function($request, $response) {
    //var_dump("---get", $request->get);
    //var_dump("---post", $request->post);
    var_dump("---cookie", $request->cookie);
    //var_dump("---file", $request->files);
    var_dump("---header", $request->header);
    //var_dump($request->server);

    $response->cookie("User", "Swoole");
    $response->header("X-Server", "Swoole");
    $response->end("<h1>Hello Swoole!</h1>");
});

$serv->start();
