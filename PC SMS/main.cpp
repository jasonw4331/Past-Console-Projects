// SendSms  - by Michael Haephrati
    BOOL SendSms(CString From, CString CountryCode, CString To,CString Message,CString *Status);
    // From - the ID or number you are sending from. This is what will appear at the recipient's cellphone.
    // CountyCode - the code of the country you are sending the SMS to (for example: 44 is for the UK
    // To - is the number you are texting to, which should not contain any leading zeros, spaces, commas, etc.
    // Message - is the message you are sending, which can be any multi lingual text
    // The status returned would be either a confirmation number along with the text "OK", which means that the message
    // was delivered, or an error code.
{
    BOOL result=FALSE;
    wstring user=L"PLACE_YOUR_USERNAME_HERE",pass=L"PLACE_YOUR_PASSWORD_HERE",request=L"";
    //
    request=L"http://sms1.cardboardfish.com:9001/HTTPSMS?S=H&UN=";
    request+=user;    // user name
    request+=L"&P=";
    request+=pass;    // password
    request+=L"&DA=";
    request+=(wstring)(CountryCode+To); // country code
    request+=L"&SA=";
    request+=(wstring)From; // From (sender ID)
    request+=L"&M=";
    CString EncodedMessage; // Message

    CString ccc;
    EncodedMessage=ConvertHex(Message)+ConvertHex( L" here you can place your marketing piech, website, etc.");

    request+=(wstring)EncodedMessage; // Message to send

    request+=L"&DC=4";
    // Indicating that this message is encoded as opposed to plain text
