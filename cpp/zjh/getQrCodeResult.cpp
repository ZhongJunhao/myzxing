#include "getQrCodeResult.h"



std::string getQrCodeResult(Ref<LuminanceSource> source)
{
	std::string ret ;
	try{
		Ref<Binarizer> binarizer;
		binarizer = new HybridBinarizer(source);
		Ref<BinaryBitmap> binary(new BinaryBitmap(binarizer));
		DecodeHints hints(DecodeHints::DEFAULT_HINT);
		Ref<QRCodeReader> reader(new QRCodeReader());
		Ref<Result> result = reader->decode(binary,hints);
		ret = result->getText()->getText();	
	}   catch (const ReaderException& e) {
		ret = "zxing::ReaderException: " + std::string(e.what());
	} catch (const zxing::IllegalArgumentException& e) {
		ret = "zxing::IllegalArgumentException: " + std::string(e.what());
	} catch (const zxing::Exception& e) {
		ret = "zxing::Exception: " + std::string(e.what());
	} catch (const std::exception& e) {
		ret = "std::exception: " + std::string(e.what());
	}
	return ret;
}