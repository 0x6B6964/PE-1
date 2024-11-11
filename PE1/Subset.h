#pragma once
struct Subset
{
private:
	unsigned int _start;
	unsigned int _end;

public:
	Subset() {
		_start = 0;
		_end = 0;
	}

	Subset(unsigned int start, unsigned int end) {
		_start = start;
		_end = end;
		
		if (_end < _start)
			_end = _start;
	}

	inline unsigned int GetStart() { return _start; }
	inline unsigned int GetEnd() { return _end; }
};

