// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;	//<Account::t>: t는 Account class의 별칭, vector: 동적배열자료형, 결론 : Account클래스벡터자료형의 타입이름을 accounts_t로 정의.
	typedef std::vector<int>								  ints_t;	//정수형벡터의 타입이름(alias)을 ints_t로 정의.
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; //pair : 두가지 다른 타입의 요소를 쌍(pair)으로 담을 수 있는 자료형이다. accounts_t::iterator : accounts_t는 아까 vector<Account::t>의 타입으로 정의된 타입이다. iterator는 컨테이너(벡터,맵,리스트)의 원소를 접근하기 위한 클래스이다. 결론 : accounts_t::iterator와 ints_t::iterator를 포함하는 타입이름 acc_int_t로 정의

	//계좌 8개 생성코드
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };	//int형 배열 선언
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );				//배열의 요소 개수 저장 = (배열의총크기/배열각요소의크기)
	accounts_t				accounts( amounts, amounts + amounts_size );				//Account클래스벡터타입의 객체 accounts선언, param1:배열시작주소, param2 : 배열끝의 다음 주소, 벡터초기화방법: 벡터를 배열로 초기화할때 인자를 두개넣어초기화함. 새로 만들어지는 벡터의 각각 요소는 당연히 Account class타입이고, 벡터클래스가 accountclass들을 만들때 인자로 들어온 배열요소들을 사용하여 만들어준다. 이때 생성자 함수가 실행되는것이다. account class의 생성자 함수의 param인 initial_deposit으로 배열값이 들어가 벡터선언시 각각의 account class(계좌)들이 입금금액으로 초기화 되는 것이다.
	accounts_t::iterator	acc_begin	= accounts.begin();								//Account클래스백터인 iterator형태의 변수선언 후 Account클래스벡터의 시작요소를 대입한다.
	accounts_t::iterator	acc_end		= accounts.end();								//acc_begin와 같은원리

	//입금할 금액 8개 생성코드
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };				//위 accounts객체 만들때와 동일하게 deposits변수 만드는 코드
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );										//위계좌만들때와 달리 int형 벡터이기 때문에 따로 생성자가 호출되지 않는다.
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	//출금할 금액 8개 생성코드
	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };			//위 accounts객체,depositㄴ객체 만들때와 동일하게 withdrawals 만드는 코드
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();


	Account::displayAccountsInfos();													//계좌 정보 출력
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );	//for_each로 acc_begin ~ acc_end까지 각각요소를 Account::displayStatus메소드로 출력

	for ( acc_int_t it( acc_begin, dep_begin );											//pair 자료형 it에 acc와 dep에 대해 반복문수행
		  it.first != acc_end && it.second != dep_end;									//for문 첫번째인자: account와 deposit객체를 가진 it, 두번쨰인자: 각 객체들의 끝을 만날때까지를 조건함. 세번째인자: 각 객체들의 index증가
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );										//account[index].makeDeposit(deposits[index]);
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
