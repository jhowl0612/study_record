package com.auction.exception;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

// 예외가 발생했을 때 예외정보를 담는 엔티티 클래스
@Data
@NoArgsConstructor
@AllArgsConstructor
public class CommonException {

    private String message;
    private String detail;
    private Date timestamp;
}
