ttt: clean
	g++ --std=c++14 main.cpp board.cpp game.cpp board_printer.cpp rules.cpp -o ttt
	./ttt

bpt: clean
	g++ --std=c++14 board_printer.cpp board_printer_test.cpp board.cpp -o bpt
	./bpt

bt: clean
	g++ --std=c++14 board_test.cpp board.cpp -o bt
	./bt

gt: clean
	g++ --std=c++14 game_test.cpp board_printer.cpp rules.cpp game.cpp board.cpp -o gt
	./gt

rt: clean
	g++ --std=c++14 rules_test.cpp rules.cpp board.cpp -o rt
	./rt

clean:
	@rm -f ttt
	@rm -f bpt
	@rm -f bt
	@rm -f gt
