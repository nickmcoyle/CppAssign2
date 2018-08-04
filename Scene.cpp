#include "Scene.h"


namespace Framework
{
	Scene::Scene()
		:width(0),
		height(0)		
	{}

	Scene::Scene(int width, int height)
		:width(width),
		height(height)		
	{}

	Scene::LayerIterator Scene::begin()
	{
		return layers.begin();
	};

	Scene::LayerIterator Scene::end()
	{
		return layers.end();
	};

	void Scene::pushBack(const Layer& layer) 
	{ 
		layers.push_back(layer); 
	};

	void Scene::pushBack(Layer&& layer) 
	{
		layers.emplace_back(std::move(layer));
	}

	void Scene::remove(const Layer& layer)
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
		throw std::invalid_argument("the layer to remove does not appear in the scene.");
	}
	
	const Scene::LayerCollection& Scene::getLayers()
	{
		return layers;
	}

	void Scene::setWidth(int width)
	{
		if (width < 0)
		{
			throw std::invalid_argument("width must be a positive integer");
		}
		this->width = width;
	}

	int const& Scene::getWidth() const
	{
		return width;
	};

	void Scene::setHeight(int height)
	{
		if (height < 0)
		{
			throw std::invalid_argument("height must be a positive integer");
		}
		this->height = height;
	}

	int const& Scene::getHeight() const
	{
		return height; 
	};
}