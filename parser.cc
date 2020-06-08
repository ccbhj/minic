// A Bison parser, made by GNU Bison 3.5.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 36 "parser.y"

#include "tokens.h"
#include "ast.h"
#include <iostream>
#include "context.h"
#include "driver.h"

#undef yylex
#define yylex drv.scanner->yylex

using ccbhj::BiOpt;
using ccbhj::UaOpt;
using ccbhj::Type;
using std::cout;
using std::endl;

#line 62 "parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.y"
namespace ccbhj {
#line 154 "parser.cc"


  /// Build a parser object.
  Parser::Parser (Driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
    , location (std::move (that.location))
  {}
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 32 "parser.y"
{
    yyla.location.begin.filename = yyla.location.end.filename = &drv.output;
}

#line 491 "parser.cc"


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 107 "parser.y"
                          { drv.ctx->programBlock = (yystack_[0].value.BLOCK); }
#line 618 "parser.cc"
    break;

  case 3:
#line 108 "parser.y"
                { cout << "empty file to parse" << endl; }
#line 624 "parser.cc"
    break;

  case 4:
#line 111 "parser.y"
               { (yylhs.value.IDENT) = new IdentifierNode((yystack_[0].value.STR)); }
#line 630 "parser.cc"
    break;

  case 5:
#line 115 "parser.y"
                               {    (yylhs.value.BLOCK) = new BlockNode(); (yylhs.value.BLOCK)->statements.push_back((yystack_[0].value.STMT)); }
#line 636 "parser.cc"
    break;

  case 6:
#line 116 "parser.y"
                                                   { (yylhs.value.BLOCK)->statements.push_back((yystack_[0].value.STMT)); }
#line 642 "parser.cc"
    break;

  case 7:
#line 119 "parser.y"
                              { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 648 "parser.cc"
    break;

  case 8:
#line 120 "parser.y"
                               { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 654 "parser.cc"
    break;

  case 9:
#line 123 "parser.y"
                                  { (yylhs.value.STMT) = new Formal((yystack_[2].value.TYPE), (yystack_[1].value.IDENT));}
#line 660 "parser.cc"
    break;

  case 10:
#line 124 "parser.y"
                                                         { (yylhs.value.STMT) = new ArrayFormal((yystack_[5].value.TYPE), (yystack_[4].value.IDENT), (yystack_[2].value.EXPR)); }
#line 666 "parser.cc"
    break;

  case 11:
#line 128 "parser.y"
              { (yylhs.value.TYPE) = Type::int_; }
#line 672 "parser.cc"
    break;

  case 12:
#line 131 "parser.y"
                                                             { (yylhs.value.STMT) = new FuncDeclNode(Type::void_, (yystack_[4].value.IDENT), (yystack_[2].value.FORMALS), (yystack_[0].value.BLOCK)); }
#line 678 "parser.cc"
    break;

  case 13:
#line 132 "parser.y"
                                                                 { (yylhs.value.STMT) = new FuncDeclNode((yystack_[5].value.TYPE), (yystack_[4].value.IDENT), (yystack_[2].value.FORMALS), (yystack_[0].value.BLOCK)); }
#line 684 "parser.cc"
    break;

  case 14:
#line 133 "parser.y"
                                                          { cout << "invalid return type" << endl; yyerrok; }
#line 690 "parser.cc"
    break;

  case 15:
#line 137 "parser.y"
               { /* no param */ (yylhs.value.FORMALS) = nullptr;}
#line 696 "parser.cc"
    break;

  case 16:
#line 138 "parser.y"
             { (yylhs.value.FORMALS) = nullptr;}
#line 702 "parser.cc"
    break;

  case 17:
#line 139 "parser.y"
        { (yylhs.value.FORMALS) = (yystack_[0].value.FORMALS); }
#line 708 "parser.cc"
    break;

  case 18:
#line 142 "parser.y"
                  { (yylhs.value.FORMALS) = new Formals(); (yylhs.value.FORMALS)->formals.push_back(static_cast<Formal*>((yystack_[0].value.STMT))); }
#line 714 "parser.cc"
    break;

  case 19:
#line 143 "parser.y"
                                   { (yystack_[2].value.FORMALS)->formals.push_back(static_cast<Formal*>((yystack_[0].value.STMT))); }
#line 720 "parser.cc"
    break;

  case 20:
#line 147 "parser.y"
                   { (yylhs.value.STMT) = new Formal((yystack_[1].value.TYPE), (yystack_[0].value.IDENT)); }
#line 726 "parser.cc"
    break;

  case 21:
#line 148 "parser.y"
                                     {(yylhs.value.STMT) = new ArrayFormal((yystack_[3].value.TYPE), (yystack_[2].value.IDENT)); }
#line 732 "parser.cc"
    break;

  case 22:
#line 152 "parser.y"
                                        { (yylhs.value.BLOCK) = (yystack_[1].value.BLOCK); }
#line 738 "parser.cc"
    break;

  case 23:
#line 153 "parser.y"
                                              { (yylhs.value.BLOCK) = nullptr;}
#line 744 "parser.cc"
    break;

  case 24:
#line 156 "parser.y"
                { (yylhs.value.BLOCK) = new BlockNode(); (yylhs.value.BLOCK)->statements.push_back((yystack_[0].value.STMT)); }
#line 750 "parser.cc"
    break;

  case 25:
#line 157 "parser.y"
                          { (yystack_[1].value.BLOCK)->statements.push_back((yystack_[0].value.STMT)); }
#line 756 "parser.cc"
    break;

  case 26:
#line 160 "parser.y"
      { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 762 "parser.cc"
    break;

  case 27:
#line 161 "parser.y"
        { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 768 "parser.cc"
    break;

  case 28:
#line 162 "parser.y"
                      { (yylhs.value.STMT) = (yystack_[0].value.BLOCK);  }
#line 774 "parser.cc"
    break;

  case 29:
#line 163 "parser.y"
        { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 780 "parser.cc"
    break;

  case 30:
#line 164 "parser.y"
        { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
#line 786 "parser.cc"
    break;

  case 31:
<<<<<<< HEAD
#line 165 "parser.y"
        { (yylhs.value.STMT) = (yystack_[0].value.STMT); }
=======
#line 167 "parser.y"
                                                         {(yylhs.value.STMT) = new SelectNode((yystack_[2].value.EXPR), (yystack_[0].value.STMT)); }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 792 "parser.cc"
    break;

  case 32:
<<<<<<< HEAD
#line 169 "parser.y"
                                                         {(yylhs.value.STMT) = new SelectNode((yystack_[2].value.EXPR), (yystack_[0].value.STMT)); }
=======
#line 168 "parser.y"
                                           {(yylhs.value.STMT) = new SelectNode((yystack_[4].value.EXPR), (yystack_[2].value.STMT), (yystack_[0].value.STMT)); }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 798 "parser.cc"
    break;

  case 33:
<<<<<<< HEAD
#line 170 "parser.y"
                                           {(yylhs.value.STMT) = new SelectNode((yystack_[4].value.EXPR), (yystack_[2].value.STMT), (yystack_[0].value.STMT)); }
=======
#line 171 "parser.y"
                     { (yylhs.value.STMT) = new ExpStmtNode((yystack_[1].value.EXPR)); }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 804 "parser.cc"
    break;

  case 34:
<<<<<<< HEAD
#line 173 "parser.y"
                     { (yylhs.value.STMT) = new ExpStmtNode((yystack_[1].value.EXPR)); }
=======
#line 172 "parser.y"
               { (yylhs.value.STMT) = nullptr; }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 810 "parser.cc"
    break;

  case 35:
<<<<<<< HEAD
#line 174 "parser.y"
               { (yylhs.value.STMT) = nullptr; }
=======
#line 175 "parser.y"
                                                       { (yylhs.value.STMT) = new WhileNode((yystack_[2].value.EXPR), (yystack_[0].value.BLOCK)); }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 816 "parser.cc"
    break;

  case 36:
<<<<<<< HEAD
#line 177 "parser.y"
                                              { (yylhs.value.STMT) = new WhileNode((yystack_[2].value.EXPR), (yystack_[0].value.STMT)); }
=======
#line 178 "parser.y"
                          { (yylhs.value.STMT) = new ReturnNode(); }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 822 "parser.cc"
    break;

  case 37:
<<<<<<< HEAD
#line 180 "parser.y"
                          { (yylhs.value.STMT) = new ReturnNode(); }
=======
#line 179 "parser.y"
                              { (yylhs.value.STMT) = new ReturnNode((yystack_[1].value.EXPR)); }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 828 "parser.cc"
    break;

  case 38:
<<<<<<< HEAD
#line 181 "parser.y"
                              { (yylhs.value.STMT) = new ReturnNode((yystack_[1].value.EXPR)); }
=======
#line 182 "parser.y"
      { (yylhs.value.EXPR) = (yystack_[0].value.EXPR); }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 834 "parser.cc"
    break;

  case 39:
<<<<<<< HEAD
#line 184 "parser.y"
      { (yylhs.value.EXPR) = (yystack_[0].value.EXPR); }
=======
#line 183 "parser.y"
                             { (yylhs.value.EXPR) = (yystack_[1].value.EXPR);}
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 840 "parser.cc"
    break;

  case 40:
<<<<<<< HEAD
#line 185 "parser.y"
                             { (yylhs.value.EXPR) = (yystack_[1].value.EXPR);}
=======
#line 184 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::plus, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 846 "parser.cc"
    break;

  case 41:
<<<<<<< HEAD
#line 186 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::plus, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
=======
#line 185 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::minus, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 852 "parser.cc"
    break;

  case 42:
<<<<<<< HEAD
#line 187 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::minus, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
=======
#line 186 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::mul, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 858 "parser.cc"
    break;

  case 43:
<<<<<<< HEAD
#line 188 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::mul, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
=======
#line 187 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::div, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 864 "parser.cc"
    break;

  case 44:
<<<<<<< HEAD
#line 189 "parser.y"
                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::div, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
=======
#line 188 "parser.y"
                             { (yylhs.value.EXPR) = new UnaryOperator(UaOpt::neg, (yystack_[0].value.EXPR));}
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 870 "parser.cc"
    break;

  case 45:
<<<<<<< HEAD
#line 190 "parser.y"
                             { (yylhs.value.EXPR) = new UnaryOperator(UaOpt::neg, (yystack_[0].value.EXPR));}
=======
#line 189 "parser.y"
                             { (yylhs.value.EXPR) = new AsgNode((yystack_[2].value.IDENT), (yystack_[0].value.EXPR)); }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 876 "parser.cc"
    break;

  case 46:
<<<<<<< HEAD
#line 191 "parser.y"
                             { (yylhs.value.EXPR) = new AsgNode((yystack_[2].value.IDENT), (yystack_[0].value.EXPR)); }
=======
#line 190 "parser.y"
                             { (yylhs.value.EXPR) = new MethodCallNode((yystack_[3].value.IDENT), (yystack_[1].value.ARGS)); }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 882 "parser.cc"
    break;

  case 47:
<<<<<<< HEAD
#line 192 "parser.y"
                             { (yylhs.value.EXPR) = new MethodCallNode((yystack_[3].value.IDENT), (yystack_[1].value.ARGS)); }
=======
#line 191 "parser.y"
                                { /* TODO  array */ }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 888 "parser.cc"
    break;

  case 48:
<<<<<<< HEAD
#line 193 "parser.y"
                             { (yylhs.value.EXPR) = new AsgNode((yystack_[2].value.IDENT), (yystack_[0].value.EXPR));}
=======
#line 192 "parser.y"
      { (yylhs.value.EXPR) = (yystack_[0].value.EXPR); }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 894 "parser.cc"
    break;

  case 49:
<<<<<<< HEAD
#line 194 "parser.y"
      { (yylhs.value.EXPR) = (yystack_[0].value.EXPR); }
=======
#line 193 "parser.y"
                             { (yylhs.value.EXPR) = (yystack_[0].value.IDENT); }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 900 "parser.cc"
    break;

  case 50:
<<<<<<< HEAD
#line 195 "parser.y"
                             { (yylhs.value.EXPR) = (yystack_[0].value.EXPR);}
=======
#line 196 "parser.y"
                                             { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::less, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 906 "parser.cc"
    break;

  case 51:
<<<<<<< HEAD
#line 196 "parser.y"
                             { (yylhs.value.EXPR) = (yystack_[0].value.IDENT); }
=======
#line 197 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::greater,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 912 "parser.cc"
    break;

  case 52:
<<<<<<< HEAD
#line 199 "parser.y"
                                              { (yylhs.value.IDENT) = new ArrayRef((yystack_[3].value.STR), (yystack_[1].value.EXPR)); }
=======
#line 198 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::equal,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 918 "parser.cc"
    break;

  case 53:
<<<<<<< HEAD
#line 201 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::less, (yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
=======
#line 199 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::nequal,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 924 "parser.cc"
    break;

  case 54:
<<<<<<< HEAD
#line 202 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::greater,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
=======
#line 200 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::eless,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 930 "parser.cc"
    break;

  case 55:
<<<<<<< HEAD
#line 203 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::equal,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
=======
#line 201 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::egreater ,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 936 "parser.cc"
    break;

  case 56:
#line 204 "parser.y"
<<<<<<< HEAD
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::nequal,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
=======
                    { (yylhs.value.EXPR) = new NumNode(std::stoi(*(yystack_[0].value.STR))); delete (yystack_[0].value.STR); }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 942 "parser.cc"
    break;

  case 57:
<<<<<<< HEAD
#line 205 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::eless,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
=======
#line 207 "parser.y"
             { (yylhs.value.ARGS) = nullptr; }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 948 "parser.cc"
    break;

  case 58:
<<<<<<< HEAD
#line 206 "parser.y"
                                      { (yylhs.value.EXPR) = new BinaryOperator(BiOpt::egreater ,(yystack_[2].value.EXPR), (yystack_[0].value.EXPR));}
=======
#line 208 "parser.y"
            { (yylhs.value.ARGS) = new ArgsNode(); (yylhs.value.ARGS)->args.push_back((yystack_[0].value.EXPR)); }
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
#line 954 "parser.cc"
    break;

  case 59:
#line 209 "parser.y"
<<<<<<< HEAD
                    { (yylhs.value.EXPR) = new NumNode(std::stoi(*(yystack_[0].value.STR))); delete (yystack_[0].value.STR); }
#line 960 "parser.cc"
    break;

  case 60:
#line 212 "parser.y"
             { (yylhs.value.ARGS) = nullptr; }
#line 966 "parser.cc"
    break;

  case 61:
#line 213 "parser.y"
            { (yylhs.value.ARGS) = new ArgsNode(); (yylhs.value.ARGS)->args.push_back((yystack_[0].value.EXPR)); }
#line 972 "parser.cc"
    break;

  case 62:
#line 214 "parser.y"
                      { (yystack_[2].value.ARGS)->args.push_back((yystack_[0].value.EXPR)); }
#line 978 "parser.cc"
    break;


#line 982 "parser.cc"
=======
                      { (yystack_[2].value.ARGS)->args.push_back((yystack_[0].value.EXPR)); }
#line 960 "parser.cc"
    break;


#line 964 "parser.cc"
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


<<<<<<< HEAD
  const signed char Parser::yypact_ninf_ = -68;
=======
  const signed char Parser::yypact_ninf_ = -47;
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9

  const signed char Parser::yytable_ninf_ = -4;

  const short
  Parser::yypact_[] =
  {
<<<<<<< HEAD
      50,    -8,    14,   -68,     9,    53,   -68,   -68,    14,   -68,
      15,   -68,    38,   -68,   -68,     6,    14,    46,    69,   -68,
      69,     2,    47,    56,   -68,    67,    78,   -68,    81,    80,
     -68,     2,     2,    18,   207,    89,   -68,   -68,    88,    60,
     -68,    56,    15,    56,     2,   151,   -68,     2,     2,    90,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   -68,   -68,   -68,    95,   204,    96,   -68,    14,   -68,
      87,   -68,   -68,   -68,   -68,   -68,   118,   -68,   -68,   -68,
     218,   -68,   228,   228,    32,   -68,    83,    83,   -68,   -68,
      64,    64,    64,    64,    64,    64,   228,     2,   -68,   136,
       2,    57,   -68,   -68,   -68,   -68,     2,   -68,   166,   -68,
     181,   228,   104,   104,    82,   -68,   104,   -68
=======
     100,    -6,    45,   -47,    47,   103,   -47,   -47,    45,   -47,
      50,   -47,    40,   -47,   -47,   118,    45,    46,    20,   -47,
      20,    55,    51,    60,   -47,    63,    73,   -47,    66,   -47,
      69,    72,    41,   -47,    60,    50,    60,    83,   -47,   -47,
     155,   -47,   155,    82,    58,    86,    76,   -47,    68,   -47,
     -47,   -47,   -47,   -47,    99,   -47,   -47,   -47,   -47,   -47,
     -47,    -2,   -47,   155,   -47,   117,   155,   155,   155,   155,
     -47,   -47,   -47,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   -47,   132,   -47,   157,   178,   178,    -1,
     168,    14,    14,   -47,   -47,   128,   128,   128,   128,   128,
     128,    85,    60,   155,   -47,   -47,   102,   -47,   178,    85,
     -47
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     0,    11,     0,     0,     5,     7,     0,     8,
       0,     4,     0,     1,     6,     0,     0,     0,    15,     9,
<<<<<<< HEAD
      15,     0,    20,     0,    16,     0,    17,    18,     0,     4,
      59,     0,     0,    51,     0,    50,    39,    49,     0,     0,
      14,     0,     0,     0,     0,     0,    45,     0,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    35,    23,     0,     0,     0,    27,     0,    28,
       0,    24,    29,    26,    30,    31,     0,    12,    19,    13,
       0,    40,    46,    61,     0,    10,    41,    42,    43,    44,
      54,    53,    55,    57,    58,    56,    48,     0,    37,     0,
       0,     0,    22,    25,    34,    52,     0,    47,     0,    38,
       0,    62,     0,     0,    32,    36,     0,    33
=======
      15,     0,    20,     0,    16,     0,    17,    18,     0,    56,
       0,     0,     0,    14,     0,     0,     0,     0,    21,    34,
       0,    23,     0,     0,     0,     0,    49,    27,     0,    24,
      28,    26,    29,    30,     0,    38,    48,    12,    19,    13,
      10,     0,    44,     0,    36,     0,     0,     0,    57,     0,
      22,    25,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,    37,     0,    45,    58,     0,
       0,    40,    41,    42,    43,    51,    50,    52,    54,    55,
      53,     0,     0,     0,    46,    47,    31,    35,    59,     0,
      32
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
  };

  const signed char
  Parser::yypgoto_[] =
  {
<<<<<<< HEAD
     -68,   -68,    -1,   -68,   106,    13,    42,   -68,    98,   -68,
      -2,   -19,   -68,   -67,   -68,   -68,   -68,   -68,   -21,   -68,
     -68,   -68,   -68
=======
     -47,   -47,    44,   -47,   105,   -47,     7,   -47,    92,   -47,
      -4,   -23,   -47,   -46,   -47,   -47,   -47,   -47,   -39,   -47,
     106,   -47
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
  };

  const signed char
  Parser::yydefgoto_[] =
  {
<<<<<<< HEAD
      -1,     4,    33,     5,     6,    67,    68,     9,    25,    26,
      27,    69,    70,    71,    72,    73,    74,    75,    76,    35,
      36,    37,    84
=======
      -1,     4,    46,     5,     6,     7,    16,     9,    25,    26,
      27,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    89
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
  };

  const signed char
  Parser::yytable_[] =
  {
<<<<<<< HEAD
      34,    12,    10,   103,    40,    29,    30,    15,    17,    13,
      45,    46,    31,     7,    19,    22,    20,    11,     7,    32,
      21,     3,    77,    80,    79,    47,    82,    83,    48,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      78,   106,     8,   107,    99,   114,   115,     8,    18,   117,
      -3,     1,    16,    -2,     1,     2,     3,    23,     2,     3,
      16,    38,    16,    29,    30,    19,     3,   101,    62,    39,
      31,    21,    63,    39,    24,     3,   108,    32,    41,   110,
      50,    51,    52,    53,    16,   111,    64,    42,    65,    66,
      29,    30,    43,     3,    44,    62,    60,    31,    85,   102,
      39,    52,    53,    61,    32,    97,   100,    29,    30,   116,
       3,    14,    62,    64,    31,    65,    66,    39,    28,     0,
       0,    32,     0,     0,     0,     0,   104,     0,     0,     0,
      64,     0,    65,    66,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,   109,     0,     0,     0,     0,     0,
       0,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    81,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   112,     0,     0,
       0,     0,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,   113,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    29,    30,     0,
       0,     0,    98,     0,    31,     0,     0,     0,     0,     0,
       0,    32,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,   105,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59
=======
      33,    61,    71,    62,    10,    65,    17,     8,   103,    83,
     104,    57,     8,    59,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    84,    24,     3,    86,    87,    88,
      90,    58,    75,    76,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    11,    29,    12,    13,    11,    39,
      18,    40,    15,    41,    32,   106,     3,    23,    42,    29,
      22,    11,    29,   110,   108,    31,    64,    43,    40,    44,
      45,    11,    29,    32,    34,    42,    39,    36,    40,   107,
      70,    32,    35,    67,    37,    42,    68,    38,    11,    29,
      69,    60,    63,    39,    43,    40,    44,    45,    32,    66,
      -3,     1,    42,    -2,     1,     2,     3,    72,     2,     3,
      14,    43,    28,    44,    45,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    85,    19,    30,    20,   109,
       0,     0,    21,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,   101,    73,    74,    75,    76,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    11,    29,
       0,     0,     0,     0,     0,    40,     0,     0,     0,   102,
       0,     0,    42,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,   105,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
  };

  const signed char
  Parser::yycheck_[] =
  {
<<<<<<< HEAD
      21,     2,    10,    70,    23,     3,     4,     8,    10,     0,
      31,    32,    10,     0,     8,    16,    10,     3,     5,    17,
      14,     6,    41,    44,    43,     7,    47,    48,    10,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      42,     9,     0,    11,    65,   112,   113,     5,    10,   116,
       0,     1,    10,     0,     1,     5,     6,    11,     5,     6,
      18,    14,    20,     3,     4,     8,     6,    68,     8,    13,
      10,    14,    12,    13,     5,     6,    97,    17,    11,   100,
      16,    17,    18,    19,    42,   106,    26,     9,    28,    29,
       3,     4,    11,     6,    14,     8,     7,    10,     8,    12,
      13,    18,    19,    15,    17,    10,    10,     3,     4,    27,
       6,     5,     8,    26,    10,    28,    29,    13,    20,    -1,
      -1,    17,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      26,    -1,    28,    29,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    11,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    11,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    11,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     3,     4,    -1,
      -1,    -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    15,    16,    17,    18,    19,    20,    21,    22,
=======
      23,    40,    48,    42,    10,    44,    10,     0,     9,    11,
      11,    34,     5,    36,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    63,     5,     6,    66,    67,    68,
      69,    35,    18,    19,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     3,     4,     2,     0,     3,     8,
      10,    10,     8,    12,    13,   101,     6,    11,    17,     4,
      16,     3,     4,   109,   103,    14,     8,    26,    10,    28,
      29,     3,     4,    13,    11,    17,     8,    11,    10,   102,
      12,    13,     9,     7,    15,    17,    10,    15,     3,     4,
      14,     8,    10,     8,    26,    10,    28,    29,    13,    13,
       0,     1,    17,     0,     1,     5,     6,     8,     5,     6,
       5,    26,    20,    28,    29,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     8,     8,    21,    10,    27,
      -1,    -1,    14,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    11,    16,    17,    18,    19,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     3,     4,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    12,
      -1,    -1,    17,    16,    17,    18,    19,    20,    21,    22,
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
      23,    24,    25,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     1,     5,     6,    33,    35,    36,    37,    38,    39,
      10,     3,    34,     0,    36,    34,    38,    42,    10,     8,
<<<<<<< HEAD
      10,    14,    34,    11,     5,    40,    41,    42,    40,     3,
       4,    10,    17,    34,    50,    51,    52,    53,    14,    13,
      43,    11,     9,    11,    14,    50,    50,     7,    10,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       7,    15,     8,    12,    26,    28,    29,    37,    38,    43,
      44,    45,    46,    47,    48,    49,    50,    43,    42,    43,
      50,    11,    50,    50,    54,     8,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    10,     8,    50,
      10,    34,    12,    45,     8,    15,     9,    11,    50,     8,
      50,    50,    11,    11,    45,    45,    27,    45
=======
      10,    14,    34,    11,     5,    40,    41,    42,    40,     4,
      52,    14,    13,    43,    11,     9,    11,    15,    15,     8,
      10,    12,    17,    26,    28,    29,    34,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    43,    42,    43,
       8,    50,    50,    10,     8,    50,    13,     7,    10,    14,
      12,    45,     8,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    11,    50,     8,    50,    50,    50,    53,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    11,    12,     9,    11,    15,    45,    43,    50,    27,
      45
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    32,    33,    33,    34,    35,    35,    36,    36,    37,
      37,    38,    39,    39,    39,    40,    40,    40,    41,    41,
      42,    42,    43,    43,    44,    44,    45,    45,    45,    45,
<<<<<<< HEAD
      45,    45,    46,    46,    47,    47,    48,    49,    49,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    51,    52,    52,    52,    52,    52,    52,    53,
      54,    54,    54
=======
      45,    46,    46,    47,    47,    48,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      51,    51,    51,    51,    51,    51,    52,    53,    53,    53
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     0,     1,     1,     2,     1,     1,     3,
       6,     1,     6,     6,     5,     0,     1,     1,     1,     3,
       2,     4,     3,     2,     1,     2,     1,     1,     1,     1,
<<<<<<< HEAD
       1,     1,     5,     7,     2,     1,     5,     2,     3,     1,
       3,     3,     3,     3,     3,     2,     3,     4,     3,     1,
       1,     1,     4,     3,     3,     3,     3,     3,     3,     1,
       0,     1,     3
=======
       1,     5,     7,     2,     1,     5,     2,     3,     1,     3,
       3,     3,     3,     3,     2,     3,     4,     4,     1,     1,
       3,     3,     3,     3,     3,     3,     1,     0,     1,     3
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "IDENTIFIER", "INT_CONST",
  "VOID", "INT", "ASSIGN", "SEMI", "COMMA", "LPAREN", "RPAREN", "RBRACE",
  "LBRACE", "LBRACKET", "RBRACKET", "PLUS", "MINUS", "MUL", "DIV",
  "GREATER", "LESS", "EQUAL", "ELESS", "EGREATER", "NEQUAL", "IF", "ELSE",
  "RETURN", "WHILE", "NEG", "NO_ELSE", "$accept", "program", "id",
  "declaration_list", "declaration", "var_declaration", "var_type",
  "func_declaration", "params", "param_list", "param", "compound_stmt",
  "stmt_list", "stmt", "selection_stmt", "expr_stmt", "iteration_stmt",
<<<<<<< HEAD
  "return_stmt", "expr", "array_ref", "comparision", "numeric", "args", YY_NULLPTR
=======
  "return_stmt", "expr", "comparision", "numeric", "args", YY_NULLPTR
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
  };


  const unsigned char
  Parser::yyrline_[] =
  {
       0,   107,   107,   108,   111,   115,   116,   119,   120,   123,
     124,   128,   131,   132,   133,   137,   138,   139,   142,   143,
<<<<<<< HEAD
     147,   148,   152,   153,   156,   157,   160,   161,   162,   163,
     164,   165,   169,   170,   173,   174,   177,   180,   181,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   199,   201,   202,   203,   204,   205,   206,   209,
     212,   213,   214
=======
     146,   147,   151,   152,   155,   156,   159,   160,   161,   162,
     163,   167,   168,   171,   172,   175,   178,   179,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     196,   197,   198,   199,   200,   201,   204,   207,   208,   209
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
    };
    const int user_token_number_max_ = 286;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 5 "parser.y"
} // ccbhj
<<<<<<< HEAD
#line 1431 "parser.cc"

#line 216 "parser.y"
=======
#line 1400 "parser.cc"

#line 211 "parser.y"
>>>>>>> 2296abc9fea7efd462473bd8d7e309aabc557ac9

void ccbhj::Parser::error(const Parser::location_type& l, const std::string& m) {
    drv.error(l, m);
}
