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

#include "../../../base/ztalib.h"

static uint16_t *last_image=0;

// Load code/memory to pcore

void ztaInitPcore(uint16_t *_image) {
   uint16_t *c_p,*pcore_p;
   int c_len,pcoreLen;
   
   if(last_image==_image)
      return;
   last_image=_image;
   
   pcore_p = _image;
   pcoreLen= pcore_p[0];
   pcore_p++;
   
   c_p = pcore_p+pcoreLen/sizeof(uint16_t);
   c_len = c_p[0];
   c_p++;
   
   c_len=c_len>>1;
   pcoreLen=pcoreLen>>2;
  
   ZTAM_GREG(0,REG_DP_VM_TOGGLE,0)=0;
   ;ZTAM_GREG(0,5,0)=(0+(11<<3));
   c_len=((c_len+3)>>2)<<2;

   // Set pcore process1's constant memory space
   // Set pcore process1's constant memory space
   if(c_len > 0) {
{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((4)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=((((c_len-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=4095;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(0+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((c_len-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(0),t01=(1),t02=(c_len-1),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((67108864)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((uint32_t)c_p)>>(((INT16)&1)));;ZTAM_GREG(19,8,0)=(1036317|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
   }
   ZTAM_GREG(0,REG_DP_VM_TOGGLE,0)=0;

   // Set pcore process0's constant memory space.
   if(c_len > 0) {
{{int t00=(0),t01=(1),t02=(0),t0=t02;ZTAM_GREG(16,8,0)=(4096)*t01;ZTAM_GREG(17,8,0)=(t0);ZTAM_GREG(18,8,0)=((4)-t00)*(4096)-1;ZTAM_GREG(24,8,0)=t00*(4096);ZTAM_GREG(5,8,0)=((((c_len-1)-(0)+(1))/(1))-1);ZTAM_GREG(8,8,0)=(1)*(1);ZTAM_GREG(12,8,0)=4095;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(4,8,0)=t00*(4096)+(0+(0))+(1<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=((t0+1)*(((1*(((c_len-1)-(0)+(1))/(1)))-1)+1));ZTAM_GREG(19,8,0)=((31|(INT16<<5))|((((0)&((1<<(MCAST_WIDTH-1))-1))+(1<<(MCAST_WIDTH-1)))<<14))|((0)<<8);}{int t00=(0),t01=(1),t02=(c_len-1),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((67108864)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((uint32_t)c_p)>>(((INT16)&1)));;ZTAM_GREG(19,8,0)=(1036317|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
   }

   // Set pcore code space
{{;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(5,8,0)=3;ZTAM_GREG(12,8,0)=3;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(16,8,0)=4;ZTAM_GREG(17,8,0)=(((pcoreLen>>1))-1);ZTAM_GREG(18,8,0)=(((pcoreLen>>1))-1);ZTAM_GREG(24,8,0)=0;ZTAM_GREG(4,8,0)=(3<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=(4*((pcoreLen>>1)));ZTAM_GREG(19,8,0)=(1032223|(INT16<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=((((pcoreLen>>1)<<2)-1)),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=(((pcoreLen>>1)<<2)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+(((uint32_t)pcore_p)>>(((INT16)&1)));;ZTAM_GREG(19,8,0)=(1036317|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
;ZTAM_GREG(0,5,0)=(0+(11<<3));
}

// Download code to stream processor
// Code for stream processor is a table lookup to map between input and output

void ztaInitStream(uint32_t _spu) {
   int spuCnt;
   if(_spu ) {
      spuCnt=*((uint16_t *)_spu);
      _spu += sizeof(uint16_t);
{{;ZTAM_GREG(8,8,0)=1;ZTAM_GREG(5,8,0)=1;ZTAM_GREG(12,8,0)=1;ZTAM_GREG(25,8,0)=0;ZTAM_GREG(16,8,0)=2;ZTAM_GREG(17,8,0)=511;ZTAM_GREG(18,8,0)=511;ZTAM_GREG(24,8,0)=0;ZTAM_GREG(4,8,0)=(2<<(11+REGISTER_DEPTH));ZTAM_GREG(26,8,0)=1024;ZTAM_GREG(19,8,0)=(1032223|(INT16<<5))|((0)<<8);}{int t00=(0),t01=(1),t02=(((spuCnt*SPU_LOOKUP_SIZE)-1)),t0=t02;ZTAM_GREG(8,8,0)=((1)*t01);ZTAM_GREG(5,8,0)=(t0);ZTAM_GREG(12,8,0)=((spuCnt*SPU_LOOKUP_SIZE)-1-t00);ZTAM_GREG(25,8,0)=t00*(1);int tbar=t00*(1)+0;ZTAM_GREG(4,8,0)=tbar+((_spu)>>(((INT16)&1)));;ZTAM_GREG(19,8,0)=(1036317|(INT16<<5))|((0)<<8);};ZTAM_GREG(0,5,0)=DP_TRANSFER_CMD(1,0,0,0,0,0,0,0,((-1)>=0)?1:0,(-1)&(3),(0));}
;ZTAM_GREG(0,5,0)=(0+(11<<3));
   }
}

// A job is finished

void ztaJobDone(unsigned int job_id) {
ZTAM_GREG(0,23,0)=((uint32_t)((0)));ZTAM_GREG(0,24,0)=(int)(job_id);;ZTAM_GREG(0,5,0)=(6+(15<<3));
}
