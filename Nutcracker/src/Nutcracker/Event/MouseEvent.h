#pragma once

namespace Nutcracker {

	class NUTCRACKER_API MouseMoveEvent : public Event {

	public:
		MouseMoveEvent(float x, float y) 
			: m_MouseX(x), mouseY(y){}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouesMovement :" << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryMouse | EventCategory::EventCategoryInput)

	private:
		float m_MouseX, m_MouseY;
	};

	class NUTCRACKER_API MouseScrolledEvent : public Event {

	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_XOffset(xOffset), m_YOffset(yOffset){}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override {
			
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << " , " << m_YOffset;
			return ss;
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryMouse | EventCategory::EventCategoryInput)

	private:
		float m_XOffset, m_YOffset;
	};

	class NUTCRACKER_API MouseButtonEvent : public Event {

	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(int button)
			:m_Button(button){}
		
		int m_Button;
	};

	class NUTCRACKER_API MouseButtonPressedEvent : public MouseButtonEvent {

	public:

		MouseButtonPressedEvent(int button):
			MouseButtonEvent(button){}

		std::string ToString() const override {
			std::strindstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class NUTCRACKER_API MouseButtonReleasedEvent : public MouseButtonEvent {

	public:

		MouseButtonReleasedEvent(int button) :
			MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::strindstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleaseds)
	};
}
