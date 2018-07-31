#include "Scene.h"

namespace Framework
{
	Scene::LayerIterator Scene::begin()
	{ 
		return layers.begin(); 
	};

	Scene::LayerIterator Scene::end()
	{
		return layers.end(); 
	};

	Scene::Scene()
		:width(0),
		height(0),
		layers({10})
	{}

	Scene::Scene(int width, int height)
		:width(width),
		height(height),
		layers({10})
	{}

	void Scene::pushBack(Layer const& layer) 
	{ 
		layers.push_back(layer); 
	};

	void Scene::pushBack(Layer&& layer) 
	{
		layers.emplace_back(std::forward<Layer>(layer));
	}

	void Scene::remove(Layer const& layer)
	{
		LayerIterator it = layers.begin();
		while (it != layers.end())
		{
			if ((*it).getAlias() == layer.getAlias() )
			{
				layers.erase(it);
				return;
			}
			else
			{
				it++;
			}
		}

	}

	void Scene::setWidth(int const& width)
	{
		this->width = width;
	}

	int const& Scene::getWidth() const
	{
		return width;
	};

	void Scene::setHeight(int const& height)
	{
		this->height = height;
	}

	int const& Scene::getHeight() const
	{
		return height; 
	};
}