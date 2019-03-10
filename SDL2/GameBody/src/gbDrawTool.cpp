#include "gbDrawTool.hpp"

gbDrawTool::gbDrawTool(SDL_Renderer* render){
	if(render == nullptr)
			abort();
	this->render = render;	
}

gbColor gbDrawTool::startDraw(SDL_Texture* dst,gbColor color){
	SDL_SetRenderTarget(dst);
	gbColor tcolor;
	SDL_GetRenderDrawColor(render,tcolor.r,tcolor.g,tcolor.b,tcolor.a);
	SDL_SetRenderDrawColor(render,color.r,color.g,color.b,color.a);
	return tcolor;
}

void gbDrawTool::endDraw(gbColor color){
	SDL_SetRenderTarget(nullptr);
	SDL_SetRenderDrawColor(render,color.r,color.g,color.b,color.a);
}

void gbDrawTool::drawLine(SDL_Texture dst,int x1,int x2,int y1,int y2,gbColor color){
		gbColor tmp = startDraw(dst,color);
		SDL_RenderDrawLine(render,x1,x2,y1,y2);	
		endDraw(tmp);
}

void gbDrawTool::drawLine(SDL_Texture* dst,gbPoint p1,gbPoint p2,gbColor color){
		drawLine(dst,p1.getX(),p1.getY(),p2.getX(),p2.getY(),color);
}

void gbDrawTool::drawCircle(SDL_Texture* dst,int centerx,int centery,int radius,gbColor color){
		gbColor tmp = startDraw(dst,color);
		for(int i=1;i<60;i++)
			SDL_RenderDrawLine(render,centerx+cos(6*i*M_PI/180)*radius,centery+sin(6*i*M_PI/180)*radius,centerx+cos(6*(i+1)*M_PI/180)*radius,centery+sin(6*(i+1)*M_PI/180)*radius);	
			SDL_RenderDrawLine(render,centerx+radius,centery,centerx+cos(6*M_PI/180)*radius,centery+sin(6*M_PI/180)*radius);	
		endDraw(tmp);
}

void gbDrawTool::drawCircle(SDL_Texture* dst,gbPoint center,int radius,gbColor color){
	drawCircle(tmp,center.x,center.y,radius,color);
}
