#pragma once
struct Subset
{
private:
	size_t _start;
	size_t _end;

public:
	Subset() {
		_start = 0;
		_end = 0;
	}

	Subset(size_t start, size_t end) {
		_start = start;
		_end = end;
		
		if (_end < _start)
			_end = _start;
	}

	inline size_t GetStart() { return _start; }
	inline size_t GetEnd() { return _end; }
};

