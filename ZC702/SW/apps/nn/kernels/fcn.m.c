//----------------------------------------------------------------------------
// Copyright [2014] [Ztachip Technologies Inc]
//
// Author: Vuong Nguyen
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except IN compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to IN writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include "../../../base/util.h"
#include "../../../base/ztalib.h"
#include "fcn.h"
#include "fcn.p.img"

extern void mycallback(int parm2);

typedef struct {
   uint32_t coef;
   uint32_t biasHi;
   uint32_t biasLo;   
   uint32_t bot;
   uint32_t top;
   int topcnt;
   int topdim;
   int botcnt;
   int botdim;
   int coeftopcnt;
   int coefbotcnt;
   int dx;
   int top_scale;
   int stream;
   int num_thread;
   int num_pcore;
} RequestFcn;

// Do fully connected layer...

static void innerProduct(void *_p,int pid) {
   RequestFcn *req=(RequestFcn *)_p;
   int index;
   int i,j;
   int npcore,nthread;
   int coeftopcnt;
   int dx2;
   int index2;
   int topfmt=UINT8;
   int botfmt=UINT8;
   int biasfmt=INT16;
   int weightfmt=UINT8;
   
   nthread=req->num_thread;
   coeftopcnt=req->coeftopcnt*IP_CHUNK_SIZE;
   dx2=req->dx*IP_CHUNK_SIZE;

{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(nthread-1),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(88);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(req->top_scale);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,0,((NUM_PCORE)-1),0,0,0,((nthread)-1),0);
   ztaTaskYield();
   for(i=(pid==0)?0:req->dx;i < req->topcnt;i += 2*req->dx) {
      index2=i*IP_CHUNK_SIZE;
      npcore=req->num_pcore;

{{int t00=(0),t01=(1),t02=((npcore)-1),t0=t02,t10=(0),t11=(1),t12=(nthread-1),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((npcore)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(72+(0));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|((biasfmt)<<5))|((0)<<8);}{int t00=(i),t01=(1),t02=(i+req->dx-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((req->topcnt)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->biasHi)>>((((biasfmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((biasfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
{{int t00=(0),t01=(1),t02=((npcore)-1),t0=t02,t10=(0),t11=(1),t12=(nthread-1),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((npcore)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(80+(0));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|((biasfmt)<<5))|((0)<<8);}{int t00=(i),t01=(1),t02=(i+req->dx-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((req->topcnt)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->biasLo)>>((((biasfmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((biasfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,4,((npcore)-1),0,0,0,((nthread)-1),0);
      ztaTaskYield();
   
      // Do innerproduct. This is a memory bound operation
         
      for(j=0,index=0;j < req->botcnt;j+=IP_CHUNK_SIZE,index++) {

{{int t00=(0),t01=(1),t02=(req->num_pcore-1),t0=t02,t10=(0),t11=(1),t12=(nthread-1),t1=t12;ZTAM_GREG(6,8,0)=(4096)*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=((4)-t00)*(4096)-1;ZTAM_GREG(22,8,0)=t00*(4096);ZTAM_GREG(13,8,0)=(256)*t11;ZTAM_GREG(14,8,0)=(t1);ZTAM_GREG(15,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(23,8,0)=t10*(256);ZTAM_GREG(17,8,0)=((((IP_CHUNK_SIZE-1)-(0)+(1))/(1))-1);ZTAM_GREG(16,8,0)=(8)*(1);ZTAM_GREG(18,8,0)=63;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(5,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=63;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(0+(0)*(8)+(0));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*(((IP_CHUNK_SIZE-1)-(0)+(1))/(1))*(((VECTOR_WIDTH-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|((weightfmt)<<5))|((0)<<8);}{int t00=(index),t01=(1),t02=(index),t0=(t02-t00),t10=(index2),t11=(1),t12=(index2+dx2-1),t1=(t12-t10);ZTAM_GREG(16,8,0)=(1*(coeftopcnt))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((req->coefbotcnt)-t00)*(1*(coeftopcnt))-1;ZTAM_GREG(24,8,0)=t00*(1*(coeftopcnt));ZTAM_GREG(8,8,0)=((1)*t11);ZTAM_GREG(5,8,0)=(t1);ZTAM_GREG(12,8,0)=((coeftopcnt)-1-t10);ZTAM_GREG(25,8,0)=t10*(1);int tbar=t00*(1*(coeftopcnt))+t10*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->coef)>>((((weightfmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((weightfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((2)>=0)?1:0,(2)&(3),(0));}
{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((npcore)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*((((8)-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((31|((botfmt)<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(j),t01=(1),t02=(j+IP_CHUNK_SIZE-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((req->botcnt)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->bot)>>((((botfmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((botfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((1)>=0)?1:0,(1)&(3),(0));}
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,18,((npcore)-1),0,0,0,((nthread)-1),0);
         if((j+IP_CHUNK_SIZE) >= req->botcnt) {
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,34,((npcore)-1),0,0,0,((nthread)-1),0);
{{int t00=(i),t01=(1),t02=(i+req->dx-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((req->topcnt)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->top)>>((((topfmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((topfmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((req->num_pcore)-1),t0=t02,t10=(0),t11=(1),t12=(nthread-1),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((req->num_pcore)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(64+(0));ZTAM_GREG(19,8,0)=(1032221|((topfmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),(0));}
         }
         ztaTaskYield();
      }
   }
}

typedef struct {
   int topcnt;
   int topdim;
   int botcnt;
   int botdim;
   int ksz;
   int stride;
   uint32_t top;
   uint32_t bot;
   int output_shift;
   uint32_t stream;
} RequestPool;

// Do pooling layer

static void pooling(void *_p,int pid) {
   RequestPool *req=(RequestPool *)_p;
   int i,j;
   int from,to;
   int np; 
   int fmt=UINT8;
   int botsz;
   int cnt,step,nt;

   np=NUM_PCORE;
   cnt=req->topcnt;
   botsz=req->botdim*req->botdim;
   step=NUM_THREAD_PER_CORE*VECTOR_WIDTH*np;
   
   if(pid==0) {
      from=0;
      to=cnt/2;
   } else {
      from=cnt/2;
      to=cnt;
   }
{{int t00=(0),t01=(1),t02=(0),t0=t02,t10=(0),t11=(1),t12=(15),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=0;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(12,8,0)=0;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(72);ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*((0)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{;ZTAM_GREG(28,8,0)=(req->output_shift);ZTAM_GREG(19,8,0)=(1034269|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,40,((np)-1),0,0,0,(15),0);
   ztaTaskYield();
 
   for(i=from;i < to;i+=step) {
      nt=NUM_THREAD_PER_CORE;

      for(j=0;j < botsz;j += POOL_BOT_SIZE) {

{{int t00=(0),t01=(1),t02=((np-1)),t0=t02,t10=(0),t11=(1),t12=((nt-1)),t1=t12,t20=(0),t21=(1),t22=((VECTOR_WIDTH-1)),t2=t22,t30=(0),t31=(1),t32=(((8)-1)),t3=t32;ZTAM_GREG(6,8,0)=(1*((nt-1)+1)*((VECTOR_WIDTH-1)+1)*(((8)-1)+1))*t01;ZTAM_GREG(7,8,0)=(t0);ZTAM_GREG(11,8,0)=(((np-1)+1)-t00)*(1*((nt-1)+1)*((VECTOR_WIDTH-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(22,8,0)=t00*(1*((nt-1)+1)*((VECTOR_WIDTH-1)+1)*(((8)-1)+1));ZTAM_GREG(13,8,0)=(1*((VECTOR_WIDTH-1)+1)*(((8)-1)+1))*t11;ZTAM_GREG(14,8,0)=(t1);ZTAM_GREG(15,8,0)=(((nt-1)+1)-t10)*(1*((VECTOR_WIDTH-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(23,8,0)=t10*(1*((VECTOR_WIDTH-1)+1)*(((8)-1)+1));ZTAM_GREG(16,8,0)=(1*(((8)-1)+1))*t21;ZTAM_GREG(17,8,0)=(t2);ZTAM_GREG(18,8,0)=(((VECTOR_WIDTH-1)+1)-t20)*(1*(((8)-1)+1))-1;ZTAM_GREG(24,8,0)=t20*(1*(((8)-1)+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=((((8)-1)+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((nt-1)+1)*((VECTOR_WIDTH-1)+1)*(((8)-1)+1))+t10*(1*((VECTOR_WIDTH-1)+1)*(((8)-1)+1))+t20*(1*(((8)-1)+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((fmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(t2+1)*(t3+1)*((0)+1));ZTAM_GREG(19,8,0)=(1034271|((fmt)<<5))|((0)<<8);}{int t00=(i),t01=(1),t02=(i+VECTOR_WIDTH*np*nt-1),t0=(t02-t00),t10=(j),t11=(1),t12=(j+POOL_BOT_SIZE-1),t1=(t12-t10);ZTAM_GREG(16,8,0)=(1*(botsz))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((cnt)-t00)*(1*(botsz))-1;ZTAM_GREG(24,8,0)=t00*(1*(botsz));ZTAM_GREG(8,8,0)=((1)*t11);ZTAM_GREG(5,8,0)=(t1);ZTAM_GREG(12,8,0)=((botsz)-1-t10);ZTAM_GREG(25,8,0)=t10*(1);int tbar=t00*(1*(botsz))+t10*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->bot)>>((((fmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),((DP_CONDITION_SRAM_FLUSH)|0));}{{int t00=(0),t01=(1),t02=(np-1),t0=t02,t10=(0),t11=(1),t12=(nt-1),t1=t12;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(6,8,0)=(256)*t11;ZTAM_GREG(7,8,0)=(t1);ZTAM_GREG(11,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(22,8,0)=t10*(256);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(8)*(1);ZTAM_GREG(12,8,0)=63;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(14,8,0)=((((VECTOR_WIDTH-1)-(0)+(1))/(1))-1);ZTAM_GREG(13,8,0)=(1)*(1);ZTAM_GREG(15,8,0)=63;ZTAM_GREG(23,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(0+(0)*(8)+(0));ZTAM_GREG(26,8,0)=((t0+1)*(t1+1)*(((1*((((8)-1)-(0)+(1))/(1))*(((VECTOR_WIDTH-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1033247|((fmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((np-1)),t0=t02,t10=(0),t11=(1),t12=((nt-1)),t1=t12,t20=(0),t21=(1),t22=((VECTOR_WIDTH-1)),t2=t22,t30=(0),t31=(1),t32=(((8)-1)),t3=t32;ZTAM_GREG(16,8,0)=(1*((nt-1)+1)*((VECTOR_WIDTH-1)+1)*(((8)-1)+1))*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=(((np-1)+1)-t00)*(1*((nt-1)+1)*((VECTOR_WIDTH-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(24,8,0)=t00*(1*((nt-1)+1)*((VECTOR_WIDTH-1)+1)*(((8)-1)+1));ZTAM_GREG(6,8,0)=(1*((VECTOR_WIDTH-1)+1)*(((8)-1)+1))*t11;ZTAM_GREG(7,8,0)=(t1);ZTAM_GREG(11,8,0)=(((nt-1)+1)-t10)*(1*((VECTOR_WIDTH-1)+1)*(((8)-1)+1))-1;ZTAM_GREG(22,8,0)=t10*(1*((VECTOR_WIDTH-1)+1)*(((8)-1)+1));ZTAM_GREG(13,8,0)=(1*(((8)-1)+1))*t21;ZTAM_GREG(14,8,0)=(t2);ZTAM_GREG(15,8,0)=(((VECTOR_WIDTH-1)+1)-t20)*(1*(((8)-1)+1))-1;ZTAM_GREG(23,8,0)=t20*(1*(((8)-1)+1));ZTAM_GREG(8,8,0)=((1)*t31);ZTAM_GREG(5,8,0)=(t3);ZTAM_GREG(12,8,0)=((((8)-1)+1)-1-t30);ZTAM_GREG(25,8,0)=t30*(1);int tbar=t00*(1*((nt-1)+1)*((VECTOR_WIDTH-1)+1)*(((8)-1)+1))+t10*(1*((VECTOR_WIDTH-1)+1)*(((8)-1)+1))+t20*(1*(((8)-1)+1))+t30*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((0))>>((((fmt))&1)));;ZTAM_GREG(19,8,0)=(1034269|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(DP_CONDITION_SRAM_FLUSH));}
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,44,((np)-1),0,0,0,(15),0);
         ztaTaskYield();       
      }
;ZTAM_GREG(0,5,0)=DP_EXE_CMD(1,62,((np)-1),0,0,0,(15),0);
      ztaTaskYield();
      
      // Output results...
        
{{int t00=(i),t01=(1),t02=(i+VECTOR_WIDTH*np*nt-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((cnt)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((req->top)>>((((fmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((fmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(np-1),t0=t02,t10=(0),t11=(1),t12=(nt-1),t1=t12;ZTAM_GREG(13,8,0)=(4096)*t01;ZTAM_GREG(14,8,0)=(t0);ZTAM_GREG(15,8,0)=((np)-t00)*(4096)-1;ZTAM_GREG(23,8,0)=t00*(4096);ZTAM_GREG(16,8,0)=(256)*t11;ZTAM_GREG(17,8,0)=(t1);ZTAM_GREG(18,8,0)=((256)-t10)*(256)-1;ZTAM_GREG(24,8,0)=t10*(256);ZTAM_GREG(5,8,0)=(((((8)-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=7;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t10*(256)+t00*(4096)+(64+(0));ZTAM_GREG(19,8,0)=(1032221|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),(0));}
   }
}

// Do concantenation layer...
// Pretty straightforward, concatenate tensor data together

void kernel_concatenate_exe(
   unsigned int _req_id,
   int _cnt,
   unsigned int *_src,
   int *_copySize,
   unsigned int *_spu,
   unsigned int *_dest
) 
{
   int i,cnt,idx;
   uint32_t spu,src,dest;
   int copySize;
   int len,remain;
   int fmt=UINT8;

   ztaInitPcore(zta_pcore_img);

   cnt=_cnt;
   for(i=0;i < cnt;i++) {
      src=_src[i];
      copySize=_copySize[i];
      spu=_spu[i];
      dest=_dest[i];
      if(spu) {
         // Load stream processor code
         ztaInitStream(spu);
      }
      remain=copySize;
      idx=0;
      while(remain > 0) {
         len=remain;
         len=ROUND(len,VECTOR_WIDTH);
         if(len > CONCATENATE_BUFSZ)
            len=CONCATENATE_BUFSZ;
{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=((((len-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=1599;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((len-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|((fmt)<<5))|((0)<<8);}{int t00=(idx),t01=(1),t02=(idx+len-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((67108864)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((src)>>((((fmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
;ZTAM_GREG(0,5,0)=(0+(11<<3));
         if(spu) {
{{int t00=(idx),t01=(1),t02=(idx+len-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((copySize)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((dest)>>((((fmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((fmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=((((len-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=1599;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),(0));}
         } else {
{{int t00=(idx),t01=(1),t02=(idx+len-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((copySize)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((dest)>>((((fmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((fmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=((((len-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=1599;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
         }
;ZTAM_GREG(0,5,0)=(0+(11<<3));
         idx += len;
         remain -= len;
      }
   }
   ztaJobDone(_req_id);
}

// Do logistic layer

void kernel_logistic_exe(
   unsigned int _req_id,
   int _copySize,
   unsigned int _src,
   unsigned int _dest,
   unsigned int _spu
) {
   int i,cnt,idx;
   uint32_t src,dest;
   int copySize;
   int len,remain;
   int fmt=UINT8;

   ztaInitPcore(zta_pcore_img);
   ztaInitStream(_spu);
   
   copySize=_copySize;
   src=_src;
   dest=_dest;

   remain=copySize;
   idx=0;
   while(remain > 0) {
      len=remain;
      len=ROUND(len,VECTOR_WIDTH);
      if(len > CONCATENATE_BUFSZ)
         len=CONCATENATE_BUFSZ;
{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=((((len-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=1599;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((len-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=(1032223|((fmt)<<5))|((0)<<8);}{int t00=(idx),t01=(1),t02=(idx+len-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((67108864)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((src)>>((((fmt))&1)));;ZTAM_GREG(19,8,0)=(1036317|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((1)>=0)?1:0,(1)&(3),(0));}
;ZTAM_GREG(0,5,0)=(0+(11<<3));
{{int t00=(idx),t01=(1),t02=(idx+len-1),t0=(t02-t00);ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((copySize)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((dest)>>((((fmt))&1)));;ZTAM_GREG(26,8,0)=((t0+1)*((0)+1));ZTAM_GREG(19,8,0)=(1036319|((fmt)<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((NUM_PCORE)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=((((len-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=1599;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(8+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(19,8,0)=(1032221|((fmt)<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((0)>=0)?1:0,(0)&(3),(0));}
;ZTAM_GREG(0,5,0)=(0+(11<<3));
      idx += len;
      remain -= len;
   }
   ztaJobDone(_req_id);
}

// Process fully-connected layer request from host

void kernel_innerProduct_exe(
   unsigned int _req_id,
   unsigned int _coef,
   unsigned int _biasHi,
   unsigned int _biasLo,
   unsigned int _bot,
   unsigned int _top,
   int _topcnt,
   int _botcnt,
   int _coeftopcnt,
   int _coefbotcnt,
   unsigned int _stream,
   int _top_scale,
   int _num_pcore,
   int _num_thread
)
{
   RequestFcn req;

   ztaInitPcore(zta_pcore_img);
   ztaInitStream(_stream);

   req.coef=_coef;
   req.biasHi=_biasHi;
   req.biasLo=_biasLo;
   req.bot=_bot;
   req.top=_top;
   req.topcnt=_topcnt;
   req.botcnt=_botcnt;
   req.coeftopcnt=_coeftopcnt;
   req.coefbotcnt=_coefbotcnt;
   req.stream=_stream;
   req.top_scale=_top_scale;
   req.num_pcore=_num_pcore;
   req.num_thread=_num_thread;
   req.dx=req.num_pcore*req.num_thread*VECTOR_WIDTH;

   ztaDualHartExecute(innerProduct,&req);

   ztaJobDone(_req_id);
}

// Process pooling layer request from host

void kernel_Pooling_exe(
   unsigned int _req_id,
   unsigned int _bot,
   unsigned int _top,
   int _ksz,
   int _stride,
   int _topcnt,
   int _topdim,
   int _botcnt,
   int _botdim,
   unsigned int _stream,
   int _output_shift
)
{
   RequestPool req;

   ztaInitPcore(zta_pcore_img);
   ztaInitStream(_stream);

   req.bot=_bot;
   req.top=_top;
   req.ksz=_ksz;
   req.stride=_stride;
   req.topcnt=_topcnt;
   req.topdim=_topdim;
   req.botcnt=_botcnt;
   req.botdim=_botdim;
   req.stream=_stream;
   req.output_shift=_output_shift;

   ztaDualHartExecute(pooling,&req);

   ztaJobDone(_req_id);
}

