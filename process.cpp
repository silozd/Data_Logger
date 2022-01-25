#include "dlcalmenu.h"
#include "ui_dlcalmenu.h"


void DLCalMenu::slider_Pressed()                    // Scroll Movement
{
    int pos;
    if(current_page == SCR_MAIN){
        pos = ui->scrollReals->verticalScrollBar()->sliderPosition();}
    if(current_page == SCR_CALIB){
        pos = ui->scrollArea->horizontalScrollBar()->sliderPosition();}
    position[0]=pos;
}
void DLCalMenu::slider_Released()                   // Scroll Movement
{
    int pos;
    if(current_page == SCR_MAIN){
        pos = ui->scrollReals->verticalScrollBar()->sliderPosition();}
    if(current_page == SCR_CALIB){
        pos = ui->scrollArea->horizontalScrollBar()->sliderPosition();}
    position[1]=pos;
}
void DLCalMenu::scroll_movement()                   // Scroll Movement
{
    int factor;
    scroll_main = ui->scrollReals -> verticalScrollBar();
    scroll_bar  = ui->scrollArea  -> horizontalScrollBar();

    if(current_page == SCR_MAIN){
        factor = scroll_main->singleStep();}
    if(current_page == SCR_CALIB){
        factor = scroll_bar->singleStep();}

    int objectW = factor;

    int pos1=position[0];
    int pos2=position[1];
    int movement= pos2-pos1;

    float counter = (float)movement/(float)objectW;
    counter = counter*10;

    if((int)counter%10 >= 5){
        counter = (int)(counter/10)+1;
    }
    else if((int)counter%10 <= -5){
        counter = (int)(counter/10)-1;
    }
    else{
        counter = (int)(counter/10);
    }
    if(current_page == SCR_MAIN){
        scroll_main->setValue(pos1+((objectW)*counter));
    }
    if(current_page == SCR_CALIB){
        scroll_bar->setValue(pos1+((objectW)*counter));
    }
}
