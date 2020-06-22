// Ilias Halemi
// 062 111 133
// March 20th, 2018

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#include <iostream>

namespace AMA {
	class ErrorState {
		char* m_errorMessage;

	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState&) = delete;
		ErrorState& operator=(const ErrorState&) = delete;
		virtual ~ErrorState();

		void clear();
		bool isClear() const;
		void message(const char*);
		const char* message() const;
	};
	std::ostream& operator<<(std::ostream&, const ErrorState&);
}
#endif // !AMA_ERRORSTATE_H

