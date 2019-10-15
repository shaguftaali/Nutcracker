#include "LayerStack.h"

Nutcracker::LayerStack::LayerStack()
{
	m_LayerInsert = m_Layers.begin();
}

Nutcracker::LayerStack::~LayerStack()
{
	for (Layer* layer : m_Layers) {
		delete layer;
	}
}

void Nutcracker::LayerStack::PushLayer(Layer * layer)
{
	m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
}

void Nutcracker::LayerStack::PushOverlay(Layer * overLayer)
{
	m_Layers.emplace_back(overLayer);
}

void Nutcracker::LayerStack::PopLayer(Layer * layer)
{
}

void Nutcracker::LayerStack::PopOverlay(Layer * overlay)
{
}
