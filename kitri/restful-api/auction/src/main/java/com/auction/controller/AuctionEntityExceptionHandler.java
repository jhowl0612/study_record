package com.auction.controller;

import com.auction.exception.CommonException;
import com.auction.exception.NoSuchUserException;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.context.request.WebRequest;
import org.springframework.web.servlet.mvc.method.annotation.ResponseEntityExceptionHandler;

import java.util.Date;

@RestController
@ControllerAdvice
public class AuctionEntityExceptionHandler extends ResponseEntityExceptionHandler {

    @ExceptionHandler(NoSuchUserException.class)
    public final ResponseEntity<Object> handleNoSuchException(Exception ex, WebRequest req){
        CommonException exMessage = new CommonException(ex.getMessage(), req.getDescription(false), new Date());

        return new ResponseEntity<>(exMessage, HttpStatus.INTERNAL_SERVER_ERROR);
    }

    @Override
    protected ResponseEntity<Object> handleMethodArgumentNotValid(
            MethodArgumentNotValidException ex,
            HttpHeaders headers,
            HttpStatus status,
            WebRequest request) {
        CommonException exMessage = new CommonException("유효성 검사 오류", ex.getBindingResult().toString(), new Date());

        return new ResponseEntity<>(exMessage, status);
    }
}
