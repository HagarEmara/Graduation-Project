#include <stdbool.h>
#include "../../../base/util.h"
#include "../../../base/ztalib.h"
#include "objdet.h"
#include "objdet.p.img"

// This structure holds all information to perform this kernel function

typedef struct {
    uint32_t score; // pointer to score buffer
    uint32_t score_result; // pointer to score result buffer
    uint32_t class_result; // pointer to class result buffer
    int numBoxes; // number of boxes
    int numClasses; // Number of classes 
} RequestObjDet;

// Finding the max score of each box by scanning through the scores of every
// classes of each box
// A box is assigned to a vector element of each thread
// Number of boxes that can be processed at same time=NUM_PCORE*NUM_THREAD*VECTOR_WIDTH=1024
// 
static void objdet(void *_p,int pid) {
    RequestObjDet *req=(RequestObjDet *)_p;
    int batchBox,batchClass;
    int i,j;
    uint32_t score;
    uint32_t score_result;
    uint32_t class_result;
    uint32_t numBoxes;
    int numBoxes2;

    batchBox = NUM_PCORE*NUM_THREAD_PER_CORE*VECTOR_WIDTH;
    batchClass = CLASS_PER_THREAD;
    if(pid==0) {
        numBoxes = ((req->numBoxes/2)/8)*8; // To make it aligned to 64bytes memory
        score = req->score;
        score_result = req->score_result;
        class_result = req->class_result;
    }
    else {
        numBoxes2=((req->numBoxes/2)/8)*8; // Number of boxes assigned to pid=0
        numBoxes = req->numBoxes - numBoxes2;
        score = req->score+numBoxes2*req->numClasses;
        score_result = req->score_result+numBoxes2;
        class_result = req->class_result+numBoxes2;
    }

    for(i=0;i < numBoxes;i += batchBox) {
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,0,((NUM_PCORE)-1),0,0,0,(15),0);
        for(j=0;j < req->numClasses;j += batchClass) {
            // Transfer scores to PCORE memory
            // If there are too many classes to fit in PCORE memory, then
            // do it several times.
            // Note the order of transfer, every boxes are assigned to a vector element of
            // every thread of evey PCORE. So that we can process many boxes simultaneouly










{{int t00=(0),t01=(1),t02=((NUM_PCORE-1)),t0=t02,t10=(0),t11=(1),t12=((NUM_THREAD_PER_CORE-1)),t1=t12,t20=(0),t21=(1),t22=((VECTOR_WIDTH-1)),t2=t22,t30=(0),t31=(1),t32=((CLASS_PER_THREAD-1)),t3=t32;ZTAM_GREG(6,8,0)=(1*((NUM_THREAD_PER_CORE-1)+1)*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1))*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=(((NUM_PCORE-1)+1)-t00)*(1*((NUM_THREAD_PER_CORE-1)+1)*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1))-1;ZTAM_GREG(22,8,0)=t00*(1*((NUM_THREAD_PER_CORE-1)+1)*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1));ZTAM_GREG(13,8,0)=(1*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1))*t11;ZTAM_GREG(14,8,0)=(t1);ZTAM_GREG(15,8,0)=(((NUM_THREAD_PER_CORE-1)+1)-t10)*(1*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1))-1;ZTAM_GREG(23,8,0)=t10*(1*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1));ZTAM_GREG(16,8,0)=(1*((CLASS_PER_THREAD-1)+1))*t21;ZTAM_GREG(17,8,0)=(t2);ZTAM_GREG(18,8,0)=(((VECTOR_WIDTH-1)+1)-t20)*(1*((CLASS_PER_THREAD-1)+1))-1;ZTAM_GREG(24,8,0)=t20*(1*((CLASS_PER_THREAD-1)+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=(((CLASS_PER_THREAD-1)+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((NUM_THREAD_PER_CORE-1)+1)*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1))+t10*(1*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1))+t20*(1*((CLASS_PER_THREAD-1)+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>(((UINT8)&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*(t3+1)*((0)+1));ZTAM_GREG(19,8,0)=(1034271|(UINT8<<5))|((0)<<8);}{int t00=(i),t01=(1),t02=(i+batchBox-1),t0=(t02-t00),t10=(j),t11=(1),t12=(j+batchClass-1),t1=(t12-t10);ZTAM_GREG(16,8,0)=(1*(req->numClasses))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((numBoxes)-t00)*(1*(req->numClasses))-1;ZTAM_GREG(24,8,0)=t00*(1*(req->numClasses));ZTAM_GREG(8,8,0)=((1)*t11);ZTAM_GREG(5,8,0)=(t1);ZTAM_GREG(12,8,0)=((req->numClasses)-1-t10);ZTAM_GREG(25,8,0)=t10*(1);int tbar=t00*(1*(req->numClasses))+t10*(1)+0;ZTAM_GREG(4,8,0)=tbar+((score)>>(((UINT8)&1)));;ZTAM_GREG(19,8,0)=(1036317|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),((DP_CONDITION_SRAM_FLUSH)|0));}{{int t00=(0),t01=(1),t02=(NUM_PCORE-1),t0=t02,t10=(0),t11=(1),t12=(NUM_THREAD_PER_CORE-1),t1=t12;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(6,8,0)=(256)*t11;ZTAM_GREG(7,8,0)=(t1);ZTAM_GREG(11,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(22,8,0)=t10*(256);ZTAM_GREG(5,8,0)=((((CLASS_PER_THREAD-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(8)*(1);ZTAM_GREG(12,8,0)=63;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(14,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=(1)*(1);ZTAM_GREG(15,8,0)=63;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(0+(0)*(8)+(0));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*(((CLASS_PER_THREAD-1)-(0)+(1))/(1))*(((VECTOR_WIDTH-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1033247|(UINT8<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((NUM_PCORE-1)),t0=t02,t10=(0),t11=(1),t12=((NUM_THREAD_PER_CORE-1)),t1=t12,t20=(0),t21=(1),t22=((VECTOR_WIDTH-1)),t2=t22,t30=(0),t31=(1),t32=((CLASS_PER_THREAD-1)),t3=t32;ZTAM_GREG(16,8,0)=(1*((NUM_THREAD_PER_CORE-1)+1)*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=(((NUM_PCORE-1)+1)-t00)*(1*((NUM_THREAD_PER_CORE-1)+1)*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1))-1;ZTAM_GREG(24,8,0)=t00*(1*((NUM_THREAD_PER_CORE-1)+1)*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1));ZTAM_GREG(6,8,0)=(1*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1))*t11;ZTAM_GREG(7,8,0)=(t1);ZTAM_GREG(11,8,0)=(((NUM_THREAD_PER_CORE-1)+1)-t10)*(1*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1))-1;ZTAM_GREG(22,8,0)=t10*(1*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1));ZTAM_GREG(13,8,0)=(1*((CLASS_PER_THREAD-1)+1))*t21;ZTAM_GREG(14,8,0)=(t2);ZTAM_GREG(15,8,0)=(((VECTOR_WIDTH-1)+1)-t20)*(1*((CLASS_PER_THREAD-1)+1))-1;ZTAM_GREG(23,8,0)=t20*(1*((CLASS_PER_THREAD-1)+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=(((CLASS_PER_THREAD-1)+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((NUM_THREAD_PER_CORE-1)+1)*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1))+t10*(1*((VECTOR_WIDTH-1)+1)*((CLASS_PER_THREAD-1)+1))+t20*(1*((CLASS_PER_THREAD-1)+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>(((UINT8)&1)));;ZTAM_GREG(19,8,0)=(1034269|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(DP_CONDITION_SRAM_FLUSH));}
            
            // Find the max score 

;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,6,((NUM_PCORE)-1),0,0,0,(15),0);
            ztaTaskYield();
        }
        // Copy result to external memory
        // Result is a 2D tensor of dimension [num_boxes][2]
        // Each box would have 2 word result,first word is the max score found
        // and second word is the class that has the max score

        // Send score_result






{{int t00=(i),t01=(1),t02=(i+batchBox-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((numBoxes)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((score_result)>>(((UINT8)&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|(UINT8<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(NUM_PCORE-1),t0=t02,t10=(0),t11=(1),t12=(NUM_THREAD_PER_CORE-1),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=15;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(64+(0)*(8)+(0));ZTAM_GREG(19,8,0)=(1032221|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}

        // Send class_result






{{int t00=(i),t01=(1),t02=(i+batchBox-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((numBoxes)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((class_result)>>(((UINT8)&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|(UINT8<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(NUM_PCORE-1),t0=t02,t10=(0),t11=(1),t12=(NUM_THREAD_PER_CORE-1),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=15;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(64+(1)*(8)+(0));ZTAM_GREG(19,8,0)=(1032221|(UINT8<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
    }
}

// To find the max score for every box after scanning through all the scores of
// every class.
//    _score : scores for each box per class
//             _score is 2D tensor of this definition: _score[_numBoxes][_numClasses]
//    _result: buffer to send back result of class+score 
//             _result is 2D tensor of this definition: _result[numBoxes][2]
//    _numBoxes: number of boxes 
//    _numClasses: number of object classes whose score are assigned for each box

void kernel_objdet_exe(
   unsigned int _req_id,
   unsigned int _score,
   unsigned int _score_result,
   unsigned int _class_result,
   int _numBoxes,
   int _numClasses
)
{
    RequestObjDet req;
    uint32_t resp;

    ztaInitPcore(zta_pcore_img);

    req.score=_score;
    req.score_result=_score_result;
    req.class_result=_class_result;
    req.numBoxes=_numBoxes;
    req.numClasses=_numClasses;

    ztaDualHartExecute(objdet,&req);

    ztaJobDone(_req_id);

    // Wait for response....
    for(;;) {
        if(ztaReadResponse(&resp))
            break;
    }  
}
