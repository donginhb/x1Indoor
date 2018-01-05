/*************************************************
  Copyright (C), 2006-2016, Aurine
  File name: 	audio_comm.c
  Author:		chenbh
  Version:  	1.0
  Date: 		2015-04-27
  Description:  ��Ƶģ�鹫�ú���
				
  History:        
    1. Date:
       Author:
       Modification:
    2. ...
*************************************************/


#include "audio_endec.h"

#define SUPERCEDED

#define	SIGN_BIT	(0x80)		/* Sign bit for a A-law byte. */
#define	QUANT_MASK	(0xf)		/* Quantization field mask. */
#define	NSEGS		(8)			/* Number of A-law segments. */
#define	SEG_SHIFT	(4)			/* Left shift for segment number. */
#define	SEG_MASK	(0x70)		/* Segment field mask. */

/* copy from CCITT G.711 specifications */
unsigned char _u2a[128] = {			/* u- to A-law conversions */
	1,	1,	2,	2,	3,	3,	4,	4,
	5,	5,	6,	6,	7,	7,	8,	8,
	9,	10,	11,	12,	13,	14,	15,	16,
	17,	18,	19,	20,	21,	22,	23,	24,
	25,	27,	29,	31,	33,	34,	35,	36,
	37,	38,	39,	40,	41,	42,	43,	44,
	46,	48,	49,	50,	51,	52,	53,	54,
	55,	56,	57,	58,	59,	60,	61,	62,
	64,	65,	66,	67,	68,	69,	70,	71,
	72,	73,	74,	75,	76,	77,	78,	79,
	81,	82,	83,	84,	85,	86,	87,	88,
	89,	90,	91,	92,	93,	94,	95,	96,
	97,	98,	99,	100,	101,	102,	103,	104,
	105,	106,	107,	108,	109,	110,	111,	112,
	113,	114,	115,	116,	117,	118,	119,	120,
	121,	122,	123,	124,	125,	126,	127,	128};

unsigned char _a2u[128] = {			/* A- to u-law conversions */
	1,	3,	5,	7,	9,	11,	13,	15,
	16,	17,	18,	19,	20,	21,	22,	23,
	24,	25,	26,	27,	28,	29,	30,	31,
	32,	32,	33,	33,	34,	34,	35,	35,
	36,	37,	38,	39,	40,	41,	42,	43,
	44,	45,	46,	47,	48,	48,	49,	49,
	50,	51,	52,	53,	54,	55,	56,	57,
	58,	59,	60,	61,	62,	63,	64,	64,
	65,	66,	67,	68,	69,	70,	71,	72,
	73,	74,	75,	76,	77,	78,	79,	79,
	80,	81,	82,	83,	84,	85,	86,	87,
	88,	89,	90,	91,	92,	93,	94,	95,
	96,	97,	98,	99,	100,	101,	102,	103,
	104,	105,	106,	107,	108,	109,	110,	111,
	112,	113,	114,	115,	116,	117,	118,	119,
	120,	121,	122,	123,	124,	125,	126,	127};

/* see libst.h */
#ifdef	SUPERCEDED

static short seg_end[8] = {0xFF, 0x1FF, 0x3FF, 0x7FF,
			    0xFFF, 0x1FFF, 0x3FFF, 0x7FFF};

static short search(short val, short *table, short size)
{
	short i;
	for (i = 0; i < size; i++) 
	{
		if (val <= *table++)
			return (i);
	}
	return (size);
}

/*
 * linear2alaw() - Convert a 16-bit linear PCM value to 8-bit A-law
 *
 * linear2alaw() accepts an 16-bit integer and encodes it as A-law data.
 *
 *		Linear Input Code	Compressed Code
 *	------------------------	---------------
 *	0000000wxyza			000wxyz
 *	0000001wxyza			001wxyz
 *	000001wxyzab			010wxyz
 *	00001wxyzabc			011wxyz
 *	0001wxyzabcd			100wxyz
 *	001wxyzabcde			101wxyz
 *	01wxyzabcdef			110wxyz
 *	1wxyzabcdefg			111wxyz
 *
 * For further information see John C. Bellamy's Digital Telephony, 1982,
 * John Wiley & Sons, pps 98-111 and 472-476.
 */
unsigned char _af_linear2alaw(short pcm_val)
	/* 2's complement (16-bit range) */
{
	short		mask;
	short		seg;
	unsigned char	aval;

	if (pcm_val >= 0) 
	{
		mask = 0xD5;		/* sign (7th) bit = 1 */
	}
	else 
	{
		mask = 0x55;		/* sign bit = 0 */
		pcm_val = -pcm_val-1;/* - 8;*/  
		if(pcm_val<0)pcm_val = 32767;
	}

	/* Convert the scaled magnitude to segment number. */
	seg = search(pcm_val, seg_end, 8);

	/* Combine the sign, segment, and quantization bits. */

	if (seg >= 8)		/* out of range, return maximum value. */
		return (0x7F ^ mask);
	else 
	{
		aval = seg << SEG_SHIFT;
		if (seg < 2)
			aval |= (pcm_val >> 4) & QUANT_MASK;
		else
			aval |= (pcm_val >> (seg + 3)) & QUANT_MASK;
		return (aval ^ mask);
	}
}

/*
 * alaw2linear() - Convert an A-law value to 16-bit linear PCM
 *
 */
short _af_alaw2linear(unsigned char a_val)	
{
	short		t;
	short		seg;

	a_val ^= 0x55;

	t = (a_val & QUANT_MASK) << 4;
	seg = ((unsigned)a_val & SEG_MASK) >> SEG_SHIFT;
	switch (seg) {
	case 0:
		t += 8;
		break;
	case 1:
		t += 0x108;
		break;
	default:
		t += 0x108;
		t <<= seg - 1;
	}
	return ((a_val & SIGN_BIT) ? t : -t);
}

#define	BIAS		(0x84)		/* Bias for linear code. */

/*
 * linear2ulaw() - Convert a linear PCM value to u-law
 *
 * In order to simplify the encoding process, the original linear magnitude
 * is biased by adding 33 which shifts the encoding range from (0 - 8158) to
 * (33 - 8191). The result can be seen in the following encoding table:
 *
 *	Biased Linear Input Code	Compressed Code
 *	------------------------	---------------
 *	00000001wxyza			000wxyz
 *	0000001wxyzab			001wxyz
 *	000001wxyzabc			010wxyz
 *	00001wxyzabcd			011wxyz
 *	0001wxyzabcde			100wxyz
 *	001wxyzabcdef			101wxyz
 *	01wxyzabcdefg			110wxyz
 *	1wxyzabcdefgh			111wxyz
 *
 * Each biased linear code has a leading 1 which identifies the segment
 * number. The value of the segment number is equal to 7 minus the number
 * of leading 0's. The quantization interval is directly available as the
 * four bits wxyz.  * The trailing bits (a - h) are ignored.
 *
 * Ordinarily the complement of the resulting code word is used for
 * transmission, and so the code word is complemented before it is returned.
 *
 * For further information see John C. Bellamy's Digital Telephony, 1982,
 * John Wiley & Sons, pps 98-111 and 472-476.
 */

/* 2's complement (16-bit range) */
unsigned char _af_linear2ulaw (short pcm_val)
{
	short		mask;
	short		seg;
	unsigned char	uval;

	/* Get the sign and the magnitude of the value. */
	if (pcm_val < 0) {
		pcm_val = BIAS - pcm_val;
		mask = 0x7F;
	} else {
		pcm_val += BIAS;
		mask = 0xFF;
	}

	/* Convert the scaled magnitude to segment number. */
	seg = search(pcm_val, seg_end, 8);

	/*
	 * Combine the sign, segment, quantization bits;
	 * and complement the code word.
	 */
	if (seg >= 8)		/* out of range, return maximum value. */
		return (0x7F ^ mask);
	else {
		uval = (seg << 4) | ((pcm_val >> (seg + 3)) & 0xF);
		return (uval ^ mask);
	}

}

/*
 * ulaw2linear() - Convert a u-law value to 16-bit linear PCM
 *
 * First, a biased linear code is derived from the code word. An unbiased
 * output can then be obtained by subtracting 33 from the biased code.
 *
 * Note that this function expects to be passed the complement of the
 * original code word. This is in keeping with ISDN conventions.
 */
short _af_ulaw2linear (unsigned char u_val)
{
	short		t;

	/* Complement to obtain normal u-law value. */
	u_val = ~u_val;

	/*
	 * Extract and bias the quantization bits. Then
	 * shift up by the segment number and subtract out the bias.
	 */
	t = ((u_val & QUANT_MASK) << 3) + BIAS;
	t <<= ((unsigned)u_val & SEG_MASK) >> SEG_SHIFT;

	return ((u_val & SIGN_BIT) ? (BIAS - t) : (t - BIAS));
}

#endif

/*************************************************
  Function:			alaw2ulaw
  Description: 		alaw ����ת�� ulaw
  Input: 		
  	1��aval			alaw ����
  Output:	
  Return:			ulaw ����
  Others:  
*************************************************/
static unsigned char alaw2ulaw(unsigned char aval)
{
	aval &= 0xff;
	return ((aval & 0x80) ? (0xFF ^ _a2u[aval ^ 0xD5]) :
	    (0x7F ^ _a2u[aval ^ 0x55]));
}

/*************************************************
  Function:			ulaw2alaw
  Description: 		ulaw ����ת�� alaw
  Input: 		
  	1��uval			ulaw ����
  Output:	
  Return:			alaw ����
  Others:  
*************************************************/
static unsigned char ulaw2alaw(unsigned char uval)
{
	uval &= 0xff;
	return ((uval & 0x80) ? (0xD5 ^ (_u2a[0xFF ^ uval] - 1)) :
	    (0x55 ^ (_u2a[0x7F ^ uval] - 1)));
}


/*************************************************
  Function:			G711Encoder
  Description: 		G711����
  Input: 		
  	1��pcm			PCM ����
  	2��size			PCM ���ݳ��� ת��short�����ݳ���
  	3��lawflag		0: alaw ������ʾulaw
  Output:	
  	1��code			���������
  Return:		 
  Others:  
*************************************************/
void G711Encoder(short *pcm, unsigned char *code, int size, int lawflag)
{
	int i;
	if(lawflag == 0)
	{
		for(i=0;i<size;i++)
		{
			code[i]=_af_linear2alaw(pcm[i]);
		}
	}
	else
	{
		for(i=0;i<size;i++)
		{
			code[i]=_af_linear2ulaw(pcm[i]);
		}
	}
}

/*************************************************
  Function:			G711Decoder
  Description: 		G711����
  Input: 		
  	1��code			G711����
  	2��size			G711���ݳ���
  	3��lawflag		0: alaw ������ʾulaw
  Output:	
  	1��pcm			���������
  Return:		 
  Others:  
*************************************************/
void G711Decoder(short *pcm, unsigned char *code, int size, int lawflag)
{
	int i;

	if(lawflag == 0)
	{
		for(i=0; i<size; i++)
		{
			pcm[i]=_af_alaw2linear(code[i]);
		}
	}
	else
	{
		for(i=0; i<size; i++)
		{
			pcm[i]=_af_ulaw2linear(code[i]);
		}
	}
}

/*************************************************
  Function:		alaw_to_ulaw
  Description: 	
  Input: 		
  Output:		  
  Return:		 
  Others:
*************************************************/
void alaw_to_ulaw(unsigned int len, unsigned char* alaw, unsigned char *ulaw)
{
	int i = 0;
	
	for (i = 0; i < len; i++)
	{
		alaw[i] &= 0xff;
		ulaw[i] = ((alaw[i] & 0x80) ? (0xFF ^ _a2u[alaw[i] ^ 0xD5]) : (0x7F ^ _a2u[alaw[i] ^ 0x55]));		
	}
}

/*************************************************
  Function:		ulaw_to_alaw
  Description: 	
  Input: 		
  Output:		  
  Return:		 
  Others:
*************************************************/
void ulaw_to_alaw(unsigned int len, unsigned char* alaw, unsigned char *ulaw)
{
	int i = 0;
	
	for (i = 0; i < len; i++)
	{
		ulaw[i] &= 0xff;
		alaw[i] = ((ulaw[i] & 0x80) ? (0xD5 ^ (_u2a[0xFF ^ ulaw[i]] - 1)) : (0x55 ^ (_u2a[0x7F ^ ulaw[i]] - 1)));
	}
}


/*************************************************
  Function:		pcm_audio_mult
  Description: 	pcm ��������
  Input: 	
  	nBitsPerSample	λ��
  Output:		  
  Return:		 
  Others:  
*************************************************/
int pcm_audio_mult(unsigned char * pData, int nLen, int nBitsPerSample, float multiple)
{
	int nCur = 0;
	if (16 == nBitsPerSample)
	{
		while (nCur < nLen)
		{
			short* volum = (short*)(pData + nCur);
			*volum = (*volum) * multiple;
			if (*volum > 32767)
			{
				*volum = 32767;
			}
			*(short*)(pData + nCur) = *volum  ;
			nCur += 2;
		}

	}
	else if (8 == nBitsPerSample)
	{
		while (nCur < nLen)
		{
			unsigned char* volum = pData + nCur;
			*volum = (*volum) * multiple;
			if (*volum > 255)
			{
				*volum = 255;
			}
			*pData  = *volum  ;
			nCur ++;
		}
	}
	return 0;
 
}
