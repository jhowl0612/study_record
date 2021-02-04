package com.auction.exception;

// 사용자 정의 exception 클래스. 사용자 정의 예외
// 널포인트exception은 런타임exception에 포함됨. 이는 unchecked exception으로, 예외처리 안 해도 컴파일은 됨

import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.ResponseStatus;

// 2XX => OK
// 4XX => 클라이언트 오류
// 5XX => 서버 오류
//@ResponseStatus(HttpStatus.NOT_FOUND)
public class NoSuchUserException extends RuntimeException{

    public NoSuchUserException(String message){
        super(message);
    }
}
