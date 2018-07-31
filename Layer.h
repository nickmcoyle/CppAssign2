#pragma once
#include "Point.h"
#include "VectorGraphic.h"   
#include <list>
#include "PlacedGraphic.h"


	namespace Framework
	{	
		
		class Layer 
		{
		private:			

			typedef std::list<PlacedGraphic> PlacedGraphicCollection;

		public:
			typedef PlacedGraphicCollection::iterator PlacedGraphicIterator;			
			typedef PlacedGraphicCollection::const_iterator const_PlacedGraphicIterator;
			PlacedGraphicIterator begin();
			PlacedGraphicIterator end();

			Layer();
			Layer(std::string const& alias);

			Layer(const Layer& other) = default;
			Layer(Layer&& other) = default;

			Layer& operator=(const Layer&) = default;
			Layer& operator=(Layer&&) = default;
			
			void insert(PlacedGraphic const& placedGraphic);
			void insert(PlacedGraphic&& placedGraphic);
			void remove(PlacedGraphic const& placedGraphic);

			void setAlias(std::string const& alias);
			void setAlias(std::string&& alias);
			std::string const& getAlias() const;

			bool operator==(const Layer& rhs) const;
			bool operator!=(const Layer& rhs) const;
		
		private:
			PlacedGraphicCollection graphics;
			std::string alias;
			
		};
		
	}

