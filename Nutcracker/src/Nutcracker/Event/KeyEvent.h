#pragma once

#include "Event.h"

class NUTCRACKER_API KeyEvent : public Event {

public:
	inline int GetKeyCode() const { return m_KeyCode; }

	EVENT_CLASS_CATEGORY(EventCategoryKeyboarg | EvemtCategoryInput)

protected:
	KeyEvent(int keycode):m_KeyCode(m_KeyCode){}
	int m_KeyCode;
};


class NUTCRACKER_API KeyPressedEvent : public KeyEvent {

public:
	KeyPressedEvent(int keycode, int repeatCount) :KeyEvent(keycode), m_RepeatCount(repeatCount) {

	}

	inline int GetRepeatCount() const { return m_RepeatCount; }

	std::string ToString() const override {
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << "repeats)";
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyPressed);

private:
	int m_RepeatCount;
};

class NUTCRACKET_API KeyReleasedEvent : public KeyEvent {

public:
	KeyReleasedEvent(int keyCode):KeyEvent(keycode){}

	std::string ToString() const override {
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_KeyCode;
		return ss.str();
	 }

	EVENT_CLASS_TYPE(KeyReleased)
		
};
